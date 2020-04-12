#include "osapi.h"
#include "user_config.h"
#include "wifi.h"

const char *WiFiMode[] =
{
		"NULL",		// 0x00
		"STATION",	// 0x01
		"SOFTAP", 	// 0x02
		"STATIONAP"	// 0x03
};
static tConnState connState = WIFI_CONNECTING;

void setup_wifi_st_mode()
{
	ESPOOLITE_LOGGING("WiFi in STATIONAP mode start configure.\r\n");
	struct station_config stationConfig;

	wifi_set_opmode((wifi_get_opmode()|STATION_MODE)&STATIONAP_MODE);
	wifi_station_disconnect();
	wifi_station_dhcpc_stop();
	wifi_station_get_config(&stationConfig);
	os_memset(stationConfig.ssid, 0, sizeof(stationConfig.ssid));
	os_memset(stationConfig.password, 0, sizeof(stationConfig.password));
	os_sprintf(stationConfig.ssid, "%s", WIFI_SSID);
	os_sprintf(stationConfig.password, "%s", WIFI_PASSWORD);
	if(!wifi_station_set_config(&stationConfig)) {
		ESPOOLITE_LOGGING("WiFi not set station config!\r\n");
	}
	wifi_station_connect();
	wifi_station_dhcpc_start();
	wifi_station_set_auto_connect(1);
	if(wifi_get_phy_mode() != PHY_MODE_11N)
		wifi_set_phy_mode(PHY_MODE_11N);
	if(wifi_station_get_auto_connect() == 0)
		wifi_station_set_auto_connect(1);
	ESPOOLITE_LOGGING("WiFi in STA mode configured.\r\n");
}

void setup_wifi_ap_mode(void)
{
	wifi_set_opmode((wifi_get_opmode()|SOFTAP_MODE)&STATIONAP_MODE);
	struct softap_config apconfig;
	if(wifi_softap_get_config(&apconfig))
	{
		wifi_softap_dhcps_stop();
		char macaddr[6];
		wifi_get_macaddr(SOFTAP_IF, macaddr);
		os_memset(apconfig.ssid, 0, sizeof(apconfig.ssid));
		os_memset(apconfig.password, 0, sizeof(apconfig.password));
		apconfig.ssid_len = os_sprintf(apconfig.ssid, "%s", WIFI_SSID);
		os_sprintf(apconfig.password, "%s", WIFI_PASSWORD);
		apconfig.authmode = AUTH_WPA_WPA2_PSK;
		apconfig.ssid_hidden = 0;
		apconfig.channel = 7;
		apconfig.max_connection = 10;
		if(!wifi_softap_set_config(&apconfig)) {
			ESPOOLITE_LOGGING("WiFi not set AP config!\r\n");
		}
		struct ip_info ipinfo;
		if(wifi_get_ip_info(SOFTAP_IF, &ipinfo)) {
			IP4_ADDR(&ipinfo.ip, 192, 168, 1, 5);
			IP4_ADDR(&ipinfo.gw, 192, 168, 1, 1);
			IP4_ADDR(&ipinfo.netmask, 255, 255, 255, 0);
			if(!wifi_set_ip_info(SOFTAP_IF, &ipinfo)) {
				ESPOOLITE_LOGGING("WiFi not set IP config!\r\n");
			} else {
				ESPOOLITE_LOGGING("CONFIGURATION WEB SERVER IP: " IPSTR "\r\n", IP2STR(&ipinfo.ip));
			}
		}
		wifi_softap_dhcps_start();
	}
	if(wifi_get_phy_mode() != PHY_MODE_11N)
		wifi_set_phy_mode(PHY_MODE_11N);
	if(wifi_station_get_auto_connect() == 0)
		wifi_station_set_auto_connect(1);
	ESPOOLITE_LOGGING("WiFi in AP mode configured.\r\n");
	if(wifi_softap_get_config(&apconfig)) {
		ESPOOLITE_LOGGING("AP config: SSID: %s, PASSWORD: %s, CHANNEL: %u\r\n", apconfig.ssid,	apconfig.password, apconfig.channel);
	}
}

tConnState wifi_check_ip(void)
{
	struct ip_info ipConfig;
	switch(wifi_station_get_connect_status())
	{
		case STATION_GOT_IP:
			wifi_get_ip_info(STATION_IF, &ipConfig);
			if(ipConfig.ip.addr != 0) {
				connState = WIFI_CONNECTED;
				ESPOOLITE_LOGGING("WiFi connected\r\n");
				ESPOOLITE_LOGGING("Start TCP connecting...\r\n");
				connState = TCP_CONNECTING;
			}
			break;
		case STATION_WRONG_PASSWORD:
			connState = WIFI_CONNECTING_ERROR;
			ESPOOLITE_LOGGING("WiFi connecting error, wrong password\r\n");
			break;
		case STATION_NO_AP_FOUND:
			connState = WIFI_CONNECTING_ERROR;
			ESPOOLITE_LOGGING("WiFi connecting error, ap not found\r\n");
			break;
		case STATION_CONNECT_FAIL:
			connState = WIFI_CONNECTING_ERROR;
			ESPOOLITE_LOGGING("WiFi connecting fail\r\n");
			break;
		default:
			connState = WIFI_CONNECTING;
			ESPOOLITE_LOGGING("WiFi connecting...\r\n");
	}
	return connState;
}

