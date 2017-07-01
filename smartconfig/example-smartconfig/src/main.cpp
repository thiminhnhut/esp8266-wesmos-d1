// Atom Editor with PlatformIO
/*
 1. https://gist.github.com/anoochit/526765176805cf19bee7
 2. http://usemodj.com/2016/08/04/esp8266-wifi-smartconfig/
*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

void SmartConfigESP8266();
void PrintWiFiStatus();

void setup(){
    Serial.begin(115200);
    SmartConfigESP8266();
}

void loop(){
    //PrintWiFiStatus();
}


void SmartConfigESP8266(){
    /* Function: Ket noi WiFi qua ESP Touch
     */
    WiFi.mode(WIFI_STA);
    delay(500);

    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        WiFi.beginSmartConfig();
        if(WiFi.smartConfigDone()){
            Serial.println("WiFi Smart Config Done.");
        }
    }
    Serial.println("");
    Serial.println("");
    WiFi.printDiag(Serial);
    Serial.println(WiFi.localIP());
}

void PrintWiFiStatus(){
    /* Function: In thong tin NetWork
     */
    Serial.printf("Connected to: ");
    Serial.print(WiFi.SSID());
    Serial.print(" Password: ");
    Serial.println(WiFi.psk());

    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}
