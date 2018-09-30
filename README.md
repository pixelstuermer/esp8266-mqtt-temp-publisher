[![License: MIT](https://img.shields.io/github/license/mashape/apistatus.svg)](https://choosealicense.com/licenses/mit/)
[![Build Status](https://travis-ci.org/pixelstuermer/esp8266-mqtt-temp-publisher.svg?branch=master)](https://travis-ci.org/pixelstuermer/esp8266-mqtt-temp-publisher)

# ESP8266/NodeMCU script for measuring and publishing MQTT temperature data
The script reads temperature data from a [DS18B20](https://create.arduino.cc/projecthub/TheGadgetBoy/ds18b20-digital-temperature-sensor-and-arduino-9cc806) temperature module and publishes it with the [public MQTT broker](http://www.mqtt-dashboard.com) from HiveMQ. When subscribing to the corresponding topic, the published messages can be verified with the HiveMQ [websocket client](http://www.hivemq.com/demos/websocket-client/) for example. Of course, other brokers can be used as well.

## Prerequisites
Tbd.

## QuickStart
Tbd.

## Configuration
Tbd.

## Build
Tbd.

## Required Libraries
* [ESP8266WiFi](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)
* [PubSubClient](https://github.com/knolleary/pubsubclient)
* [OneWire](https://github.com/PaulStoffregen/OneWire)
* [DallasTemperature](https://github.com/milesburton/Arduino-Temperature-Control-Library)
