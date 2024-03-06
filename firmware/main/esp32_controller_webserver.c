#include "esp32_controller_webserver.h"
#include "esp32_spiffs.h"
#include "esp32_http.h"
#include "esp_err.h"

esp_err_t get_web_handler(httpd_req_t *req)
{
    const char *resp = esp32_spiffs_read_file("code.txt");
    httpd_resp_send(req, resp, HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}

httpd_handle_t esp32_webServer_init(){
    httpd_handle_t server = esp32_http_server_init();

    httpd_uri_t get_web_uri = {
        .uri = "/webServer",
        .method = HTTP_GET,
        .handler = get_web_handler,
        .user_ctx = NULL};

    httpd_register_uri_handler(server, &get_web_uri);
    return server;
}