idf_component_register(
    SRCS "esp32_sntp.c" "esp32_ping.c" "esp32_ip_url.c"
    INCLUDE_DIRS "include"
    REQUIRES esp_http_client
)
