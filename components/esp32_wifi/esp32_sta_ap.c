#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"

#define WIFI_SSID "Huynh_đây_Huynh_đây"
#define WIFI_PASS "012345678"
#define STA_SSID "NATAES-01"
#define STA_PASS "nataes8899"

static const char *TAG = "wifi_example";

static esp_err_t event_handler(void *ctx, system_event_t *event)
{
    switch (event->event_id)
    {
    case SYSTEM_EVENT_AP_START:
        ESP_LOGI(TAG, "Access Point started");
        break;

    case SYSTEM_EVENT_STA_START:
        ESP_LOGI(TAG, "Station started");
        esp_wifi_connect();
        break;

    case SYSTEM_EVENT_STA_CONNECTED:
        ESP_LOGI(TAG, "Station connected to AP");
        break;

    default:
        break;
    }
    return ESP_OK;
}

void wifi_init_sta()
{
    wifi_config_t wifi_config = {
        .sta = {
            .ssid = STA_SSID,
            .password = STA_PASS,
        },
    };

    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
}

void wifi_init_softap()
{
    wifi_config_t wifi_config = {
        .ap = {
            .ssid = WIFI_SSID,
            .password = WIFI_PASS,
            .max_connection = 4,
            .authmode = WIFI_AUTH_WPA_WPA2_PSK,
        },
    };

    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_AP, &wifi_config));
}

void esp32_sta_ap_init()
{
    // ESP_ERROR_CHECK(nvs_flash_init());
    tcpip_adapter_init();

    ESP_ERROR_CHECK(esp_event_loop_init(event_handler, NULL));

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_APSTA));
    wifi_init_softap();
    wifi_init_sta();

    ESP_ERROR_CHECK(esp_wifi_start());
}
