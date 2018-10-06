[![License: MIT](https://img.shields.io/github/license/mashape/apistatus.svg)](https://choosealicense.com/licenses/mit/)
[![Build Status](https://travis-ci.org/pixelstuermer/esp8266-mqtt-temp-publisher.svg?branch=master)](https://travis-ci.org/pixelstuermer/esp8266-mqtt-temp-publisher)

# ESP8266/NodeMCU Script for Measuring and Publishing MQTT Temperature Data
The script reads temperature data from a [DS18B20](https://create.arduino.cc/projecthub/TheGadgetBoy/ds18b20-digital-temperature-sensor-and-arduino-9cc806) temperature module and publishes it with the [public MQTT broker](http://www.mqtt-dashboard.com) of HiveMQ. Of course, other brokers can be used as well. When subscribing to the corresponding topic, the published messages can be verified (using the HiveMQ [websocket client](http://www.hivemq.com/demos/websocket-client/) for example).

## Prerequisites
* [Arduino IDE](https://www.arduino.cc/en/Main/Software) (or a text editor and the [Arduino CLI](https://playground.arduino.cc/Learning/CommandLine))
* Additional boards (ESP8266 or NodeMCU)
* Additional [libraries](#required-libraries) (to support Wifi, MQTT, OneWire and the temperature sensor)
* Possibly [Python](https://www.python.org/downloads/) and [Esptool](https://github.com/espressif/esptool) (for flashing the binary)

## Getting Started
1. Download the [mqtt-temp-publisher.ino](https://github.com/pixelstuermer/esp8266-mqtt-temp-publisher/blob/master/mqtt-temp-publisher.ino) file or clone this repository using `git clone`
2. Change the required variables as shown [below](#configuration)
3. Add additional boards as explained [here](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/) (or use the Arduino CLI as explained [here](https://github.com/arduino/Arduino/blob/master/build/shared/manpage.adoc))
4. [Build](#building) the binary
5. [Flash](#installing) the firmware to your ESP8266 or NodeMCU board

## Configuration
The following variables need to be set to tailor the application to your needs. `mqttBroker` and `mqttPort` can remain unchanged if the public broker of HiveMQ is to be used. Also, the [publishing interval](https://github.com/pixelstuermer/esp8266-mqtt-temp-publisher/blob/master/mqtt-temp-publisher.ino#L47) can be changed (default is `60000` milliseconds).

    wifiSsid = "{WIFI name}";
    wifiPassword = "{WIFI password}";

    mqttBroker = "{MQTT broker url}";                // default is "broker.hivemq.com"
    mqttPort = {MQTT broker port};                   // default is 1883
    mqttClientId = "{MQTT client ID}";
    mqttTopic = "{MQTT topic}";

    oneWire({data pin of your temperature sensor});  // default is D4

## Building

### Compiling and Flashing in one Step
Using the Arduino IDE, the script can be compiled and uploaded in one step: Select a board (ESP8266 or NodeMCU) from within `Tools > Board` and choose the correct serial port for uploading from within `Tools > Serial Port`. Then click `Sketch > Upload` to compile the code and flash the firmware in one step.

Using the Arduino CLI, the script can be compiled and uploaded using `{path to arduino cli}/arduino --upload --board {board information} --port {portname} {path to scripts }/mqtt-temp-publisher.ino` as explained [here](https://github.com/arduino/Arduino/blob/master/build/shared/manpage.adoc) as well.

### Only Compiling the Binary
If you simply want to build the binary without flashing it, select `Sketch > Export compiled Binary` within the Arduino IDE.

Otherwise, the Arduino CLI can be utilized as well using `{path to arduino cli}/arduino --verify --board {board information} --preserve-temp-files --pref build.path={path to binary} {path to script}/mqtt-temp-publisher.ino`.

## Installing
When having only compiled the binary (as explained [above](#only-compiling-the-binary)), the firmware can be flashed using esptool for example: `python {path to esptool}/esptool.py --port {portname} write_flash -fm dio 0x00000 {path to binary}/mqtt-temp-publisher.ino.bin`.

## Required Libraries
* [ESP8266WiFi](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)
* [PubSubClient](https://github.com/knolleary/pubsubclient)
* [OneWire](https://github.com/PaulStoffregen/OneWire)
* [DallasTemperature](https://github.com/milesburton/Arduino-Temperature-Control-Library)
