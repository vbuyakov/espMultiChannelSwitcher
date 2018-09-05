#include "config.h"
#include "lampDrive.h"
#include "buttons.h"
#include "notifier.h"
#include "iotServer.h"
void setup() {
  initLamps();
  initButtons();
  #if _DBG_
    Serial.begin(9600);
    Serial.println();
    Serial.printf("Ready");
  #endif
  #if _USE_WIFI_SRV_
    initIotServer();
  #endif
}

void loop() {
checkButtons();
#if _USE_WIFI_SRV_
  iotHandleCLient();
#endif
}
