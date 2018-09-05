#ifndef config_h
#define config_h
// IF True then log to serial 9600
#define _DBG_ true 
// IF True enable WiFi server
#define _USE_WIFI_SRV_ true
// If True homeBridge notify enabled
#define _USE_HB_NOTIFY_ true

//Lamps pins
const int lampPin_1 = 4;
const int lampPin_2 = 5;
//Buttons pins
const int buttonPin_1 = 0;
const int buttonPin_2 = 14;

//Home bridge Notification server server setup
const String notificationSrvUrl = "http://192.168.0.1:8080"; //Url for notification server
const String notificationSrvPwd = "your_pwd"; //Use same pwd for all devices
const String devicesNames[2] = ["lamp-1", "lamp-2"]; //Names in notification server config

//WiFi server setup
const String ssid = "XXXXXXXX";       // SSID Name
const String password = "XXXXXXXX";       // password
const String iotServerToken = "Your-device-token";      // This device access  token
const String iotServerName = "IOT_lamps";          // Host name of this Device, can be any
const String srvIp = "192.168.0.xxx"; // where xx is the desired IP Address
const String srvGateway = "192.168.0.1"; // set gateway to match your network
const String srvSubnet ="255.255.255.0"; // set subnet mask to match your network


const int lampPins[2] = {lampPin_1, lampPin_2};
const int buttonPins[2] = {buttonPin_1, buttonPin_2};
#endif
