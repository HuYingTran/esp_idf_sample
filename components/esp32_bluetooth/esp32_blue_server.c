// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>
// #include <esp_system.h>
// #include <nvs_flash.h>
// #include <esp_bt.h>

// void init_bluetooth() {
//     esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
//     esp_err_t ret;

//     ret = esp_bt_controller_init(&bt_cfg);
//     if (ret != ESP_OK) {
//         ESP_LOGE(TAG, "Initialize controller failed: %s", esp_err_to_name(ret));
//         return;
//     }

//     ret = esp_bt_controller_enable(ESP_BT_MODE_BLE);
//     if (ret != ESP_OK) {
//         ESP_LOGE(TAG, "Enable controller failed: %s", esp_err_to_name(ret));
//         return;
//     }

//     ret = esp_bluedroid_init();
//     if (ret != ESP_OK) {
//         ESP_LOGE(TAG, "Initialize Bluedroid failed: %s", esp_err_to_name(ret));
//         return;
//     }

//     ret = esp_bluedroid_enable();
//     if (ret != ESP_OK) {
//         ESP_LOGE(TAG, "Enable Bluedroid failed: %s", esp_err_to_name(ret));
//         return;
//     }
// }

// #include <esp_gap_ble_api.h>
// #include <esp_gatts_api.h>

// #define GATTS_TAG "GATTS"

// // UUID của dịch vụ và đặc trưng, bạn cần thay đổi nếu cần
// #define GATTS_SERVICE_UUID        0x00FF
// #define GATTS_CHAR_UUID           0xFF01

// void gatts_profile_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param) {
//     switch (event) {
//         case ESP_GATTS_REG_EVT:
//             break;

//         case ESP_GATTS_READ_EVT:
//             break;

//         case ESP_GATTS_WRITE_EVT:
//             break;

//         case ESP_GATTS_EXEC_WRITE_EVT:
//             break;

//         case ESP_GATTS_MTU_EVT:
//             break;

//         case ESP_GATTS_CONF_EVT:
//             break;

//         case ESP_GATTS_UNREG_EVT:
//             break;

//         default:
//             break;
//     }
// }

// void init_gatts() {
//     esp_ble_gatts_profile_inst_t gatts_profile = {
//         .gatts_cb = gatts_profile_event_handler,
//         .app_id = 0,
//         .conn_id = ESP_GATT_IF_NONE,
//         .service_id = {
//             .is_primary = true,
//             .id = {
//                 .uuid = {
//                     .len = ESP_UUID_LEN_16,
//                     .uuid = { GATTS_SERVICE_UUID },
//                 },
//             },
//         },
//         .char_id = {
//             .uuid = {
//                 .len = ESP_UUID_LEN_16,
//                 .uuid = { GATTS_CHAR_UUID },
//             },
//             .max_len = 0,
//             .init_len = 0,
//             .p_value = NULL,
//         },
//     };

//     esp_ble_gatts_app_register(&gatts_profile);
// }
