#include <Arduino.h>
#include "lampDrive.h"
#include "config.h"
#include "notifier.h"

int lampStates[2] = {0, 0};

void initLamps() {
    pinMode(lampPin_1, OUTPUT);
    digitalWrite(lampPin_1, LOW);
    
    pinMode(lampPin_2, OUTPUT);
    digitalWrite(lampPin_2, LOW);
}
void turnOnLamp(int lampNum) {
    #if _DBG_
        Serial.printf("Lamp is On - %d \n",lampNum);
    #endif
    digitalWrite(lampPins[lampNum-1], HIGH);
    lampStates[lampNum-1] = 1;
    #if _USE_HB_NOTIFY_
        sendNotify(lampNum, 1);
    #endif
}
void turnOffLamp(int lampNum) {
    #if _DBG_
        Serial.printf("Lamp is Off - %d \n",lampNum);
    #endif
    #if _USE_HB_NOTIFY_
        sendNotify(lampNum, 0);
    #endif
    digitalWrite(lampPins[lampNum-1], LOW);
    lampStates[lampNum-1] = 0;
}

int getLampState(int lampNum) {
    return lampStates[lampNum-1];
}
