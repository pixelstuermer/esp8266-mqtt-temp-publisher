#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const char* wifiSsid = "{wifi_ssid}";
const char* wifiPassword = "{wifi_password}";

const char* mqttBroker = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttClientId = "{mqtt_client_id}";
const char* mqttTopic = "{mqtt_topic}";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

OneWire oneWire({oneWirePin});
DallasTemperature tempSensor(&oneWire);

void setup() {
  WiFi.begin(wifiSsid, wifiPassword);
  WiFi.mode(WIFI_STA);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  mqttClient.setServer(mqttBroker, mqttPort);
  mqttClient.connect(mqttClientId);
  delay(500);
}

void loop() {
  if (!mqttClient.connected()) {
    mqttClient.connect(mqttClientId);
  }

  float currentTemp = readTemp();
  char currentTempArray[6];
  dtostrf(currentTemp, 6, 2, currentTempArray);
  mqttClient.publish(mqttTopic, currentTempArray);
  delay(5000);
}

float readTemp() {
  float temp;
  do {
    tempSensor.requestTemperatures();
    temp = tempSensor.getTempCByIndex(0);
  } while (temp == (85.0) || temp == (-127.0));
  return temp;
}
