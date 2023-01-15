#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "esp_wpa2.h"
#include <eduroam-connect.hpp>
#include <string.h>

const char* ssid = "eduroam";

void connectToEduroam(const char *username, const char *password) {
    Serial.println();
    Serial.print("Connecting to network: ");
    Serial.println(ssid);

    WiFi.disconnect(true);
    WiFi.mode(WIFI_STA);

    esp_wifi_sta_wpa2_ent_set_identity((uint8_t *) username, strlen(username));
    esp_wifi_sta_wpa2_ent_set_username((uint8_t *) username, strlen(username));
    esp_wifi_sta_wpa2_ent_set_password((uint8_t *) password, strlen(password));
    esp_wifi_sta_wpa2_ent_enable();

    WiFi.begin(ssid);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address set: ");
    Serial.println(WiFi.localIP());
}