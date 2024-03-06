idf_component_register(
    SRCS "esp32_blue_server.c" "esp32_blue.c" "esp32_ibeacon.c"
    INCLUDE_DIRS "include"
    REQUIRES nvs_flash bt
)
