#include <esp_http_server.h>
#include <esp_log.h>
#define TAG "esp32_server_http"

#define MIN(a,b) ((a<b)?a:b)

esp_err_t get_handler(httpd_req_t *req)
{
    const char resp[] = "<h1>Hello World</h1>";
    httpd_resp_send(req, resp, HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}

esp_err_t post_handler(httpd_req_t *req)
{
    char content[100];
    size_t recv_size = MIN(req->content_len, sizeof(content));
    int ret = httpd_req_recv(req, content, recv_size);
    if (ret <= 0) {
        if (ret == HTTPD_SOCK_ERR_TIMEOUT) {
            httpd_resp_send_408(req);
        }
        return ESP_FAIL;
    }
    ESP_LOGI(TAG, "%s", content);
    return ESP_OK;
}

httpd_handle_t esp32_http_server_init()
{
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    httpd_handle_t server = NULL;
    if (httpd_start(&server, &config) == ESP_OK)
    {
        // Do something
    }

    httpd_uri_t get_uri = {
        .uri = "/test",
        .method = HTTP_GET,
        .handler = get_handler,
        .user_ctx = NULL};

    httpd_register_uri_handler(server, &get_uri);

    httpd_uri_t post_uri = {
        .uri = "/test",
        .method = HTTP_POST,
        .handler = post_handler,
        .user_ctx = NULL};

    httpd_register_uri_handler(server, &post_uri);

    return server;
}

void esp32_stop_server(httpd_handle_t server){
    if(server){
        httpd_stop(server);
    }
}