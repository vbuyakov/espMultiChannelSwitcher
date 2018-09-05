Simple remote lamp switcher based on ESP8266 to use with homebridge.

Before compile rename `config.example.h` to `config.h` 
and set parameters inside it


I used it with homebrige plugins [HTTP-SWITCH](https://github.com/Supereg/homebridge-http-switch#readme)
And [Notifications servrer](https://github.com/Supereg/homebridge-http-notification-server)

In the folder `homebridge-configs` you can fin examples of configuration for these homebridge plugins.

Also your can connect buttons or remote control to switch channels w/o wifi access.
Buttons should be connect to ground. Pins are configurable.

PS: If Notifications servrer will down with `password` parameter use my [fork](https://github.com/vbuyakov/homebridge-http-notification-server) or just apply fix from [PR](https://github.com/Supereg/homebridge-http-notification-server/pull/2) to original repository.

Author: [Viktor Buiakov](http://softdeveloper.ru)

