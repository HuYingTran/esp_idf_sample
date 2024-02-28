#include <driver/gpio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <driver/adc.h>

#define pin1 34
#define pin2 35

void setup_pin(){
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_6,ADC_ATTEN_DB_0);
    

    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_7,ADC_ATTEN_DB_0);
    
}

void esp32_volt_meter(){
    setup_pin();
    while (1)
    {
        int v1 = adc1_get_raw(ADC1_CHANNEL_6);
        int v2 = adc1_get_raw(ADC1_CHANNEL_7);
        printf("\nvolt: %d",v1-v2);
        vTaskDelay(100);
    }
    
}