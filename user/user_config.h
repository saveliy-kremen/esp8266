#define WIFI_SSID		"awl"
#define WIFI_PASSWORD	"as123098"
#define TCPSERVERIP 	"87.244.176.211"
#define TCPSERVERPORT 	2090

#define PLATFORM_DEBUG

// Debug output
#ifdef ESPOOLITE_LOGGING
#undef ESPOOLITE_LOGGING
#define ESPOOLITE_LOGGING(...) ets_uart_printf(__VA_ARGS__);
#else
#define ESPOOLITE_LOGGING(...)
#endif
