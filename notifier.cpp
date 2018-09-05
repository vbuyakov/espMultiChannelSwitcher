#include <Arduino.h>
#include "notifier.h"
#include "config.h"
#include <ESP8266HTTPClient.h>

HTTPClient http;

void sendNotify(int lampNum, int newState) {
    #if _DBG_
        Serial.printf("Notify that lamp %d set to %d \n", lampNum, newState);
    #endif
    String msg = "{\"characteristic\": \"On\",\"value\": "+ String(newState)+"}";
    String uri = notificationSrvUrl + "/" + devicesNames[lampNum-1];
    if (notificationSrvPwd.length() > 0) {
        uri += "?password=" + notificationSrvPwd;
    }
    #if _DBG_
        Serial.printf(msg.c_str());
        Serial.printf(uri.c_str());
    #endif
    http.begin(uri);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpCode = http.POST(msg);
    http.end();

}