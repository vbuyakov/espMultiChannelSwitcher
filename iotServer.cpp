#include "iotServer.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "config.h"
#include "lampDrive.h"

ESP8266WebServer server(80); // Iot web server


void handleRoot() { // empty request, for debug 
  server.send(200, "text/plain", "Hello! I am " + iotServerName);
}

void handleNotFound() { // unknown requests
  server.send(404, "text/plain", "not found");
}

int getLampNum() { // get lamp num from Get param
  return server.arg("lamp").toInt();
}
 
bool checkAccess() { // check  acess token
  String token = server.arg("token");
  if (iotServerToken != token) {
    server.send(401, "text/plain", "access denied");
    return false;
  }
  return true;
}

void handleStatus() { // Check lamp status
  if (checkAccess()) {
    String message = String(getLampState(getLampNum()));
    server.send(200, "text/plain", message);
  }
}

void handleOn() { // Switch ON lamp
  if (checkAccess()) {
    turnOnLamp(getLampNum());
    server.send(200, "text/plain", "success");
  }
}

void handleOff() { // Switch off lamp
  if (checkAccess()) {
    turnOffLamp(getLampNum());
    server.send(200, "text/plain", "success");
  }
}

void iotHandleCLient() { //handleClient wrapper for root sketch
  server.handleClient();
}

void initIotServer() { //Init server
  IPAddress ip; ip.fromString(srvIp);
  IPAddress gateway; gateway.fromString(srvGateway);
  IPAddress subnet; subnet.fromString(srvSubnet);

  WiFi.config(ip, gateway, subnet);
  WiFi.hostname(iotServerName);
  WiFi.begin(ssid.c_str(), password.c_str());

  #if _DBG_
    Serial.printf("Connecting to %s ", ssid.c_str());
  #endif
  // Wait  WiFi connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    #if _DBG_
        Serial.print(".");
    #endif
  }
  #if _DBG_
    Serial.println("Connected with IP address: ");
    Serial.println(WiFi.localIP());
  #endif
  
  // Set up routes
  server.on("/", handleRoot);
  server.on("/on", HTTP_GET, handleOn);
  server.on("/off", HTTP_GET, handleOff);
  server.on("/status", HTTP_GET, handleStatus);
  server.onNotFound(handleNotFound);
  //Start server
  server.begin();
}
