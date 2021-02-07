# Examples of connections between ESP8266 - RaspberryPi

[GitHub](https://github.com/acbernardez17/ESP8266-Raspi)

[More projects](https://github.com/acbernardez17)

## Prerequisites

### ESP8266

Libraries

1. `#include <esp8266wifi.h>` necessary to start a WIFI connection
2. `#include <wifiudp.h>` tools to work with UDP on ESP

### Raspberry PI

Requirements

1. Python 3
2. Static IP (optional but recommended)

### Enviroment

*This is optional, everyone is free to use other IDE's or Hardware*

1. IDE **ARDUINO 1.8.13**
2. BOARD **ESP8266 D1 mini**
3. RbPI **Raspberry Pi4 4Gb**

## Examples

*Based on  a Client-Server model*

### UDP_PingPong

#### Abstract

ESP8266 will send a Ping and Server(RbPi) will reply with Pong. EASY

It will be through UDP_Datagrams containing a message(PING|PONG). It's important that both sites have the same port (it's not necessary but it is easiest to understand in this way).

Code it's very simple and it's explained inside.

NOTE: Once RbPi sends out the first Pong the entire enviroment will be within an infinite loop.
