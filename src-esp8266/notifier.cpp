#include <Arduino.h>
#include "notifier.h"
#include "config.h"

void sendNotify(int lampNum, int newState) {
    #if _DBG_
        Serial.printf("Notify that lamp %d set to %d \n", lampNum, newState);
    #endif
}