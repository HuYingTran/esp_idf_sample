// #define CONFIG_PARTITION_TABLE_CUSTOM_APP_BIN_OFFSET   0x10000
// #define CONFIG_PARTITION_TABLE_CUSTOM_APP_BIN_SIZE     0x60000
// #define CONFIG_PARTITION_TABLE_CUSTOM_FILESYSTEM_OFFSET  0x70000
#include "stdio.h"
#include "string.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_spiffs.h"

#define TAG "ESP32 SPIFFS"

esp_err_t esp32_setup_spiffs()
{
    // Khởi tạo và định dạng SPIFFS
    esp_vfs_spiffs_conf_t conf = {
        .base_path = "/spiffs",
        .partition_label = "explorer",
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

char *esp32_spiffs_read_file(char *file_name)
{
    char *path_spiffs = "/spiffs/";
    strcat(path_spiffs,file_name);
    FILE *file = fopen(path_spiffs, "r");
    if (file == NULL) {
        printf("Failed to open file for reading\n");
        return;
    }
    //Kích thước file
    fseek(file, 0, SEEK_END);   //Đưa con trỏ về cuối
    size_t size = ftell(file);  //Kích thước
    fseek(file, 0, SEEK_SET);   //Đưa con trỏ về đầu

    char *data = (char*)malloc(size + 1);
    fread(data, 1, size, file);
    fclose(file);
    data[size] = '\0';

    return (char*)data;

    // char buffer[1000];

    // // Đọc một dòng từ tệp
    // while (fgets(buffer, sizeof(buffer), f) != NULL) {
    //     printf("%s", buffer);
    // }
}
