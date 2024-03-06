idf_component_register(SRCS "main.c" "esp32_read_write.c" "esp32_controller_webserver.c"
                    INCLUDE_DIRS ".")
spiffs_create_partition_image(explorer ../../data FLASH_IN_PROJECT)