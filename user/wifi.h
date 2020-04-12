#include "user_interface.h"

#ifndef USER_WIFI_H_
#define USER_WIFI_H_

typedef enum {
	WIFI_CONNECTING,
	WIFI_CONNECTING_ERROR,
	WIFI_CONNECTED,
	TCP_DISCONNECTED,
	TCP_CONNECTING,
	TCP_CONNECTING_ERROR,
	TCP_CONNECTED,
	TCP_SENDING_DATA_ERROR,
	TCP_SENT_DATA
} tConnState;

void setup_wifi_ap_mode(void);
void setup_wifi_st_mode(void);
tConnState wifi_check_ip(void);

#endif /* USER_WIFI_H_ */
