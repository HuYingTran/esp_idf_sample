#include <stdio.h>
#include <driver/gpio.h>
#include <nvs_flash.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp32_wifi.h"
#include "esp32_http.h"
#include "esp32_other.h"
#include "esp32_spiffs.h"
#include "esp32_bluetooth.h"
#include "esp_ibeacon_api.h"
#include "esp32_volt.h"
#include "esp32_tcp_ip.h"
#include "esp32_i2c_lcd16x2.h"

#include "esp32_read_write.h"
#include "esp32_controller_webserver.h"

#define BTN_GPIO 0

#include <driver/i2c.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include "sdkconfig.h"
#include "HD44780.h"

#define LCD_ADDR 0x27
#define SDA_PIN  21
#define SCL_PIN  22
#define LCD_COLS 16
#define LCD_ROWS 2

// void LCD_DemoTask(void* param)
// {
//     char num[20];
//     printf("\nstart");
//     while (true) {
//       LCD_home();
//       LCD_clearScreen();
//       LCD_writeStr("16x2 I2C LCD");
//       vTaskDelay(3000 / portTICK_RATE_MS);
//       LCD_clearScreen();
//       LCD_writeStr("Lets Count 0-10!");
//       vTaskDelay(3000 / portTICK_RATE_MS);
//       LCD_clearScreen();
//       for (int i = 0; i <= 10; i++) {
//         printf("%d",i);
//           LCD_setCursor(8, 1);
//           sprintf(num, "%d", i);
//           LCD_writeStr(num);
//           vTaskDelay(1000 / portTICK_RATE_MS);
//       }
//     }
// }

void app_main(void)
{

  esp_err_t ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
  {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(ret);

  // wifi_init_sta();  // Wifi station
  esp32_sta_ap_init();

  // esp32_http_request(); // http request

  // char *url = "pong.soracom.io";
  // esp32_convert_url_ip(url);  // conevert url to ip

//   gpio_pad_select_gpio(BTN_GPIO);
//   /* Set the GPIO as a push/pull output */
//   gpio_set_direction(BTN_GPIO, GPIO_MODE_INPUT); // chân input
//   gpio_set_pull_mode(BTN_GPIO, GPIO_PULLUP_ONLY);

//   int i = gpio_get_level(BTN_GPIO);
// bool el_ocpp_mode_status = false;
// bool el_ocpp_mode_state = true;

// int trangthai = 1;

// while(1){
//   int i = gpio_get_level(BTN_GPIO);
//   // printf("\n%d",i);
//   if(!i){
//     if(trangthai){
//       printf("\nthoat ocpp");
//       trangthai = 0;
//       el_ocpp_mode_state = false;
//     }else{
//       printf("\ntvao ocpp");
//       trangthai = 1;
//       el_ocpp_mode_state = true;
//     }
//     vTaskDelay(100 / portTICK_RATE_MS);
//   }





//     if(el_ocpp_mode_state){
//         if(!el_ocpp_mode_status){
//             el_ocpp_mode_status = true;
//             printf("\ninit");
//         }
//         printf("\nmain");
//     } else {
//         // printf("\nstates false");
//         if(el_ocpp_mode_status){
//             el_ocpp_mode_status = false;
//             printf("\ncleanup");
//         }
//     }
//     vTaskDelay(100 / portTICK_RATE_MS);
// }


  // printf("\n %d\n", i);
  // printf("\nhuynh");

  // // void init_bluetooth();
  // // void init_gatts();
  // esp32_setup_spiffs();
  // esp32_spiffs_write();
  // vTaskDelay(1000/portTICK_PERIOD_MS);
  // esp32_spiffs_read();

  // esp32_blue_init();
  // esp32_ibeacon_loop();

  // while(1){
    // esp32_lcd();//   vTaskDelay(1000/portTICK_PERIOD_MS);
  // }
  // esp32_volt_meter();
  // esp32_tcp_server();
  // esp32_init();
  // char str[120] = "huynh";
  // esp32_lcd();
  // esp32_http_server_init();
  esp32_setup_spiffs();
  // esp32_read_file_write_spiffs();
  esp32_spiffs_read();
  esp32_webServer_init();
  printf("\nend");
}
