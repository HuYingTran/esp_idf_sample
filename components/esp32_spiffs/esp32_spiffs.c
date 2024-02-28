// #define CONFIG_PARTITION_TABLE_CUSTOM_APP_BIN_OFFSET   0x10000
// #define CONFIG_PARTITION_TABLE_CUSTOM_APP_BIN_SIZE     0x60000
// #define CONFIG_PARTITION_TABLE_CUSTOM_FILESYSTEM_OFFSET  0x70000
#include "stdio.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_spiffs.h"

#define TAG "ESP32 SPIFFS"

esp_err_t esp32_setup_spiffs()
{
    // Khởi tạo và định dạng SPIFFS
    esp_vfs_spiffs_conf_t conf = {
        .base_path = "/spiffs",
        .partition_label = "mo",
        .max_files = 5,
        .format_if_mount_failed = true};

    esp_err_t ret = esp_vfs_spiffs_register(&conf);

    if (ret != ESP_OK)
    {
        if (ret == ESP_FAIL)
        {
            printf("Failed to mount or format filesystem\n");
        }
        else if (ret == ESP_ERR_NOT_FOUND)
        {
            printf("Failed to find SPIFFS partition\n");
        }
        else
        {
            printf("Failed to initialize SPIFFS (%s)\n", esp_err_to_name(ret));
        }
    }
    return ret;
}

esp_err_t esp32_spiffs_write()
{
    FILE *f = fopen("/spiffs/example.txt", "w");
    if (f == NULL)
    {
        printf("Failed to open file for writing\n");
        return ESP_FAIL;
    }
    fprintf(f, "Hello from SPIFFS!\n");
    fclose(f);    
    ESP_LOGI(TAG,"written");
    return ESP_OK;
}

void esp32_spiffs_read()
{
    FILE *f = fopen("/spiffs/example.txt", "r");
    if (f == NULL)
    {
        printf("Failed to open file for reading\n");
        return;
    }
    char buffer[100];

    // Đọc một dòng từ tệp
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }
}
