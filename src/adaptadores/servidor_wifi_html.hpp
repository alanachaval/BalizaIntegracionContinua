#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_SERVIDOR_WIFI_HTML_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_SERVIDOR_WIFI_HTML_H_

#include <avr/pgmspace.h>

namespace adaptadores
{

class ServidorWiFiHtml
{
  public:
    const char *const top_html[] PROGMEM = {
        "HTTP/1.1 200 OK"
        "Content-type:text/html"
        "Connection: close"
        ""
        "<!DOCTYPE html><html>"
        "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
        "<link rel=\"icon\" href=\"data:,\">"
        "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}"
        ".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;"
        "text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}"
        ".button2 {background-color: #555555;}</style></head>"
        "<body><h1>ESP32 Web Server</h1>"};
    const int top_html_length = 12;
    const char *const on_html[] PROGMEM = {
        "<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>"};
    const int on_html_length = 1;
    const char *const off_html[] PROGMEM = {
        "<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>"};
    const int off_html_length = 1;
    const char *const bottom_html[] PROGMEM = {
        "</body></html>"
        ""};
    const int bottom_html_length = 2;
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_SERVIDOR_WIFI_HTML_H_