Simple remote lamp switcher based on ESP8266 to use with homebridge.

Before compile rename `config.h.example` to `config.h` 
and set parameters inside it


I used it with [HTTP-SWICH](https://github.com/Supereg/homebridge-http-switch#readme) with folowing configuration 
```
{
            "accessory": "HTTP-SWITCH",
            "name": "Bedrom first lamp",
            "httpMethod": "GET",
            "onUrl": "http://192.168.0.172/on?token=qqq&lamp=1",
            "offUrl": "http://192.168.0.172/off?token=qqq&lamp=1",
            "statusUrl": "http://192.168.0.172/status?token=qqq&lamp=1"
          },
          {
            "accessory": "HTTP-SWITCH",
            "name": "Bedrom second lamp",
            "httpMethod": "GET",
            "onUrl": "http://192.168.0.172/on?token=qqq&lamp=2",
            "offUrl": "http://192.168.0.172/off?token=qqq&lamp=2",
            "statusUrl": "http://192.168.0.172/status?token=qqq&lamp=2"
          }   
```

Also your connect buttons to switch channels w/o wifi access.
Buttons should be connect to ground. Pins are configurable.

Author: [Viktor Buiakov](http://softdeveloper.ru)

