#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Wifi setup
const char* wifiSsid = "{wifi_ssid}";
const char* wifiPassword = "{wifi_password}";

// Mqtt setup
const char* mqttBroker = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttClientId = "{mqtt_client_id}";
const char* mqttTopic = "{mqtt_topic}";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

// Temperature sensor setup
OneWire oneWire(D4);
DallasTemperature tempSensor(&oneWire);

// Connecting to Wifi and Mqtt broker
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

// Publishing temperature data every some seconds
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

// Reading the actual temperature data
float readTemp() {
  float temp;
  do {
    tempSensor.requestTemperatures();
    temp = tempSensor.getTempCByIndex(0);
  } while (temp == (85.0) || temp == (-127.0));
  return temp;
}
