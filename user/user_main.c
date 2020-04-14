#include "user_interface.h"
#include "ets_sys.h"
#include "mem.h"
#include "osapi.h"
#include "espconn.h"

#include "wifi.h"
#include "../driver/uart.h"
#include "user_config.h"

#include "../services/esp8266.pb.h"
#include "../services/pb_common.h"
#include "../services/pb.h"
#include "../services/pb_encode.h"
#include "../services/pb_decode.h"

static char macaddr[6];
static ETSTimer WiFiLinker;
uint8_t buffer[128];
size_t message_length;

//Обязательная функция!
   uint32 ICACHE_FLASH_ATTR user_rf_cal_sector_set(void)
   {
    enum flash_size_map size_map = system_get_flash_size_map();
    uint32 rf_cal_sec = 0;
    switch (size_map)
        {
           case FLASH_SIZE_4M_MAP_256_256:
           rf_cal_sec = 128 - 8;
           break;

           case FLASH_SIZE_8M_MAP_512_512:
           rf_cal_sec = 256 - 5;
           break;

           case FLASH_SIZE_16M_MAP_512_512:
           case FLASH_SIZE_16M_MAP_1024_1024:
           rf_cal_sec = 512 - 5;
           break;

           case FLASH_SIZE_32M_MAP_512_512:
           case FLASH_SIZE_32M_MAP_1024_1024:
           rf_cal_sec = 1024 - 5;
           break;

           default:
           rf_cal_sec = 0;
           break;

        }
    return rf_cal_sec;
   }

	static void ICACHE_FLASH_ATTR
	at_tcpclient_sent_cb(void *arg) {
		#ifdef PLATFORM_DEBUG
		ESPOOLITE_LOGGING("Send callback\r\n");
		#endif
		// Данные отправлены, отключаемся от TCP-сервера
		struct espconn *pespconn = (struct espconn *)arg;
		espconn_disconnect(pespconn);
	}

	static void ICACHE_FLASH_ATTR
	at_tcpclient_discon_cb(void *arg) {
		struct espconn *pespconn = (struct espconn *)arg;
		// Отключились, освобождаем память
		os_free(pespconn->proto.tcp);
		os_free(pespconn);
		#ifdef PLATFORM_DEBUG
		ESPOOLITE_LOGGING("Disconnect callback\r\n");
		#endif
	}

	static void ICACHE_FLASH_ATTR
	at_tcpclient_connect_cb(void *arg)
	{
		struct espconn *pespconn = (struct espconn *)arg;
		#ifdef PLATFORM_DEBUG
		ESPOOLITE_LOGGING("TCP client connect\r\n");
		#endif
		// callback функция, вызываемая после отправки данных
		espconn_regist_sentcb(pespconn, at_tcpclient_sent_cb);
		// callback функция, вызываемая после отключения
		espconn_regist_disconcb(pespconn, at_tcpclient_discon_cb);

		uint16 adc = system_adc_read();
		ESPOOLITE_LOGGING("%d\r\n", adc );
		v1_DataRequest request = v1_DataRequest_init_zero;
		request.adc = adc;
		pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
		bool status = pb_encode(&stream, v1_DataRequest_fields, &request);
		message_length = stream.bytes_written;
		if (!status) {
			ESPOOLITE_LOGGING("Failed to encode");
		} else {
			ESPOOLITE_LOGGING("%d\r\n", message_length);
			int i;
			for(i = 0; i<message_length; i++) {
				ESPOOLITE_LOGGING("%02X", buffer[i]);
			}
			ESPOOLITE_LOGGING("\r\n");
			espconn_sent(pespconn, buffer, message_length);
		}
	}

	static void ICACHE_FLASH_ATTR
	senddata()
	{
		char info[150];
		char tcpserverip[15];
		struct espconn *pCon = (struct espconn *)os_zalloc(sizeof(struct espconn));
		if (pCon == NULL)
		{
			#ifdef PLATFORM_DEBUG
			ESPOOLITE_LOGGING("TCP connect failed\r\n");
			#endif
			return;
		}
		pCon->type = ESPCONN_TCP;
		pCon->state = ESPCONN_NONE;
		// Задаем адрес TCP-сервера, куда будем отправлять данные
		os_sprintf(tcpserverip, "%s", TCPSERVERIP);
		uint32_t ip = ipaddr_addr(tcpserverip);
		pCon->proto.tcp = (esp_tcp *)os_zalloc(sizeof(esp_tcp));
		pCon->proto.tcp->local_port = espconn_port();
		// Задаем порт TCP-сервера, куда будем отправлять данные
		pCon->proto.tcp->remote_port = TCPSERVERPORT;
		os_memcpy(pCon->proto.tcp->remote_ip, &ip, 4);
		// Регистрируем callback функцию, вызываемую при установки соединения
		espconn_regist_connectcb(pCon, at_tcpclient_connect_cb);
		// Можно зарегистрировать callback функцию, вызываемую при реконекте, но нам этого пока не нужно
		//espconn_regist_reconcb(pCon, at_tcpclient_recon_cb);
		// Вывод отладочной информации
		#ifdef PLATFORM_DEBUG
		os_sprintf(info,"Start espconn_connect to " IPSTR ":%d\r\n",
			   IP2STR(pCon->proto.tcp->remote_ip),
			   pCon->proto.tcp->remote_port);
		ESPOOLITE_LOGGING(info);
		#endif
		// Установить соединение с TCP-сервером
		espconn_connect(pCon);
	}

	static void ICACHE_FLASH_ATTR timer(void *arg)
	{
		// Отключаем таймер проверки wi-fi
		os_timer_disarm(&WiFiLinker);
		if (wifi_check_ip() == TCP_CONNECTING) {
			senddata();
		}
		os_timer_setfn(&WiFiLinker, (os_timer_func_t *)timer, NULL);
		os_timer_arm(&WiFiLinker, 1000, 0);
	}

	void ICACHE_FLASH_ATTR user_init(void)
	{
		uart_init(BIT_RATE_115200, BIT_RATE_115200);
		os_delay_us(1000);
		setup_wifi_st_mode();
		os_delay_us(1000);

		os_timer_disarm(&WiFiLinker);
		os_timer_setfn(&WiFiLinker, (os_timer_func_t *)timer, NULL);
		os_timer_arm(&WiFiLinker, 1000, 0);

	}

