#include <Arduino.h>
#include "buttons.h"
#include "config.h"
#include "lampDrive.h"

void initButtons() {
    pinMode(buttonPin_1, INPUT_PULLUP);
    pinMode(buttonPin_2, INPUT_PULLUP);
}

void checkButtons() {
    checkButton(1);
    checkButton(2);
}

void checkButton(int btnNum) {
    if (digitalRead(buttonPins[btnNum-1]) == LOW )
    {
        if (getLampState(btnNum) ==1) {
            turnOffLamp(btnNum);
        } else {
            turnOnLamp(btnNum);
        }
        delay(500);
    }
}