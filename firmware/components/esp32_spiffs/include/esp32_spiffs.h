#include "esp_err.h"

esp_err_t esp32_setup_spiffs();
esp_err_t esp32_spiffs_write();
char *esp32_spiffs_read_file(char *file_name)