[![License: MIT](https://img.shields.io/github/license/mashape/apistatus.svg)](https://choosealicense.com/licenses/mit/)
[![Build Status](https://travis-ci.org/pixelstuermer/esp8266-mqtt-temp-publisher.svg?branch=master)](https://travis-ci.org/pixelstuermer/esp8266-mqtt-temp-publisher)

# ESP8266/NodeMCU script for measuring and publishing MQTT temperature data
The script reads temperature data from a [DS18B20](https://create.arduino.cc/projecthub/TheGadgetBoy/ds18b20-digital-temperature-sensor-and-arduino-9cc806) temperature module and publishes it with the [public MQTT broker](http://www.mqtt-dashboard.com) of HiveMQ. Of course, other brokers can be used as well. When subscribing to the corresponding topic, the published messages can be verified (using the HiveMQ [websocket client](http://www.hivemq.com/demos/websocket-client/) for example).

## Prerequisites
* [Arduino IDE](https://www.arduino.cc/en/Main/Software) (or the [Arduino CLI](https://playground.arduino.cc/Learning/CommandLine) and a text editor)
* Additional boards (ESP8266 or NodeMCU) as explained [here](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/)
* Additional [libraries](#required-libraries) (to support Wifi, MQTT, OneWire and the temperature sensor)
* Possibly [Python](https://www.python.org/downloads/) and [Esptool](https://github.com/espressif/esptool) (for flashing the binary)

## Getting Started
1. Download the [mqtt-temp-publisher.ino](https://github.com/pixelstuermer/esp8266-mqtt-temp-publisher/blob/master/mqtt-temp-publisher.ino) file or clone this repository using `git clone`
2. Change the required variables as shown [below](#configuration)
3. [Build](#building) the binary
4. [Flash](#installing) the firmware to your ESP8266 or NodeMCU board

## Configuration
The following variables need to be set to tailor the application to your needs. `mqttBroker` and `mqttPort` can remain unchanged if the [public broker](http://www.mqtt-dashboard.com) of HiveMQ is to be used. Also, the [publishing interval](https://github.com/pixelstuermer/esp8266-mqtt-temp-publisher/blob/master/mqtt-temp-publisher.ino#L47) can be changed (default is `60000` milliseconds).

    wifiSsid = "{WIFI name}";
    wifiPassword = "{WIFI password}";

    mqttBroker = "{MQTT broker url}";                // default is "broker.hivemq.com"
    mqttPort = {MQTT broker port};                   // default is 1883
    mqttClientId = "{MQTT client ID}";
    mqttTopic = "{MQTT topic}";

    oneWire({data pin of your temperature sensor});  // default is D4

## Building
Tbd.

## Installing
Tbd.

## Required Libraries
* [ESP8266WiFi](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)
* [PubSubClient](https://github.com/knolleary/pubsubclient)
* [OneWire](https://github.com/PaulStoffregen/OneWire)
* [DallasTemperature](https://github.com/milesburton/Arduino-Temperature-Control-Library)
