#include "esp_err.h"
#include "esp_log.h"
#include "stdio.h"

#define TAG "esp_file"

esp_err_t esp32_read_file_write_spiffs() {
    FILE *file;
    FILE *file_spifffs;
    char ch;
    char *path_file = "code.txt";
    file = fopen(path_file,"r");

    file_spifffs = fopen("/spiffs/code.txt", "w");
    while ((ch = fgetc(file)) != EOF) {
        fputc(ch,file_spifffs);
    }
    fclose(file);
    fclose(file_spifffs);
    return ESP_OK;
}
