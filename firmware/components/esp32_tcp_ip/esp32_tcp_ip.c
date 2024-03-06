#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "lwip/netdb.h"

#include "sys/fcntl.h"
#include "lwip/dns.h"

#define TAG "esp32_tcp"

#define MESSAGE "Hello TCP Client!!"
#define LISTENQ 2

void tcp_server(void *pvParam){
    ESP_LOGI(TAG,"TCP server start");
    
    struct sockaddr_in tcpServerAddr;   // tao dia chi socket cho server
    struct sockaddr_in remote_addr;     // tao dia chi socket cho client

    // gan dia chi cho tcpServer
    tcpServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    tcpServerAddr.sin_family = AF_INET;
    tcpServerAddr.sin_port = htons(3000);
    // tao bo nho dem
    char recv_buf[64];
    int s, r;
    int cs;
    static unsigned int socklen;
    socklen = sizeof(remote_addr);

    while(1){
        // tạo socket
        s = socket(AF_INET, SOCK_STREAM, 0);
        if(s<0){
            ESP_LOGI(TAG, "allocate fail");
            vTaskDelay(1000/portTICK_PERIOD_MS);
            continue;
        }
        ESP_LOGI(TAG, "allocate done");
        // gan dia chi cho socket
        int b = bind(s, (struct sockaddr *)&tcpServerAddr, sizeof(tcpServerAddr));
        if(b!=0){
            ESP_LOGI(TAG, "bind fail");
            close(s);
            vTaskDelay(1000/portTICK_PERIOD_MS);
            continue;
        }
        ESP_LOGI(TAG, "bind done");
        // dat server lang nghe client
        if(listen(s,LISTENQ)!=0){
            ESP_LOGI(TAG, "listen fail");
            close(s);
            vTaskDelay(1000/portTICK_PERIOD_MS);
            continue;
        }
        ESP_LOGI(TAG, "listen done");
        while(1){
            // socket client = server accept
            ESP_LOGI(TAG, "accept");
            cs = accept(s,(struct sockaddr*)&remote_addr, &socklen);
            if(cs<0){
                ESP_LOGI(TAG,"fail");
            }
            ESP_LOGI(TAG, "new");
            fcntl(cs,F_SETFL,O_NONBLOCK);
            do{
                bzero(recv_buf, sizeof(recv_buf));
                r = recv(cs, recv_buf, sizeof(recv_buf)-1,0);
                for(int i =0;i<r;i++){
                    putchar(recv_buf[i]);
                }
            }while(r>0);
            ESP_LOGI(TAG,"doc xong %d", r);
            if(write(cs, MESSAGE, strlen(MESSAGE))<0){
                ESP_LOGI(TAG,"send fail");
                close(s);
                vTaskDelay(1000/portTICK_PERIOD_MS);
                continue;
            }
            ESP_LOGI(TAG,"send success");
            close(cs);
        }
        ESP_LOGI(TAG, "server open in 5 seconds");
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
}

void esp32_tcp_server(){
    xTaskCreate(&tcp_server,"tcp_server",4096,NULL,5,NULL);
}