#include <driver/i2c.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include "sdkconfig.h"
#include "HD44780.h"
#include "esp_log.h"

#define TAG "esp32_lcd16x2"

#define LCD_ADDR 0x27
#define SDA_PIN  21
#define SCL_PIN  22
#define LCD_COLS 16
#define LCD_ROWS 2

void LCD_DemoTask(void* param)
{
    printf("\nstart");
    // while (true) {
        LCD_home();
        LCD_clearScreen();
        LCD_writeStr("16x2 I2C LCD");
        vTaskDelay(3000 / portTICK_RATE_MS);
    // }
}

void esp32_lcd()
{
    ESP_LOGI(TAG, "lcd init");
    LCD_init(LCD_ADDR, SDA_PIN, SCL_PIN, LCD_COLS, LCD_ROWS);
    // xTaskCreate(&LCD_DemoTask, "Demo Task", 2048, NULL, 5, NULL);
    // while(1){
    LCD_home();
    LCD_clearScreen();
    LCD_writeStr("16x2 I2C LCD");
    vTaskDelay(3000 / portTICK_RATE_MS);
    LCD_home();
    LCD_clearScreen();
    LCD_writeStr("D");
    vTaskDelay(3000 / portTICK_RATE_MS);
    LCD_home();
    LCD_clearScreen();
    LCD_writeStr("16x2 I2C LCD");
    vTaskDelay(3000 / portTICK_RATE_MS);
    // }
}

void esp32_init(){
    ESP_LOGI(TAG, "lcd init");
    LCD_init(LCD_ADDR, SDA_PIN, SCL_PIN, LCD_COLS, LCD_ROWS);
}

void esp32_lcd_print(){
    LCD_home();
    LCD_clearScreen();
    LCD_writeStr("huynh");
}