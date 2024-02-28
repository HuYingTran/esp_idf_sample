#include "lwip/ip_addr.h"
#include <sys/socket.h>
#include <netdb.h>
#include "esp_log.h"

#define TAG "ESP IpToUrl"

esp_err_t esp32_convert_url_ip(char *endpoint)
{
    esp_err_t err = ESP_OK;
    struct addrinfo *res = NULL;
    struct addrinfo hints;
    ip_addr_t endpoint_ip;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    memset(&endpoint_ip, 0, sizeof(endpoint_ip));
    if (getaddrinfo(endpoint, NULL, &hints, &res) != 0)
    {
        err = ESP_FAIL;
        ESP_LOGE(TAG, "Convert URL fail");
        return err;
    }
    if (res->ai_family == AF_INET)
    {
        struct in_addr addr4 = ((struct sockaddr_in *)(res->ai_addr))->sin_addr;
        inet_addr_to_ip4addr(ip_2_ip4(&endpoint_ip), &addr4);
    }
    ESP_LOGI(TAG, "From %s" ,ipaddr_ntoa(&endpoint_ip));
    return err;
}