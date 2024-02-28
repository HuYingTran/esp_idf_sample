// #include <string.h>
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>
// #include <esp_log.h>
// #include <esp_bt.h>
// #include <esp_gap_ble_api.h>
// #include <esp_gatts_api.h>
// #include "esp_bt_main.h"

// #define TAG "IBEACON"

// // UUID của iBeacon
// static const uint8_t iBeaconUUID[16] = {0x00, 0x00, 0x00, 0x00,
//                                         0x00, 0x00, 0x00, 0x00,
//                                         0x00, 0x00, 0x00, 0x00,
//                                         0x00, 0x00, 0x00, 0x00};

// void esp32_ibeacon(void) {
//     esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
//     esp_err_t ret;

//     // Khởi tạo Bluetooth Controller
//     ret = esp_bt_controller_init(&bt_cfg);
//     if (ret != ESP_OK) {
//         ESP_LOGE(TAG, "%s initialize controller failed", __func__);
//         return;
//     }

//     // Enable Bluetooth Controller
//     ret = esp_bt_controller_enable(ESP_BT_MODE_BLE);
//     if (ret != ESP_OK) {
//         ESP_LOGE(TAG, "%s enable controller failed", __func__);
//         return;
//     }

//     // Khởi tạo Bluetooth Stack
//     ret = esp_bluedroid_init();
//     if (ret != ESP_OK) {
//         ESP_LOGE(TAG, "%s initialize bluedroid failed", __func__);
//         return;
//     }

//     // Enable Bluetooth Stack
//     ret = esp_bluedroid_enable();
//     if (ret != ESP_OK) {
//         ESP_LOGE(TAG, "%s enable bluedroid failed", __func__);
//         return;
//     }

//     // Cấu hình iBeacon
//     esp_ble_ibeacon_tx_power_t tx_power = ESP_BLE_IBEACON_TX_POWER_MAX;
//     esp_ble_ibeacon_t ibeacon_data;
//     memcpy(ibeacon_data.uuid, iBeaconUUID, sizeof(iBeaconUUID));
//     ibeacon_data.major = 0x1234;  // Giá trị Major của iBeacon
//     ibeacon_data.minor = 0x5678;  // Giá trị Minor của iBeacon
//     ibeacon_data.measured_power = -59;  // Công suất đo được khi thiết bị ở khoảng cách 1m

//     esp_ble_config_ibeacon_data(&ibeacon_data, &tx_power);

//     // Bắt đầu phát iBeacon
//     ret = esp_ble_gap_config_adv_data(&ibeacon_data);
//     if (ret != ESP_OK) {
//         ESP_LOGE(TAG, "%s config adv data failed", __func__);
//         return;
//     }

//     ESP_LOGI(TAG, "iBeacon started");
// }
