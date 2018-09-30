#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* wifiSsid = "{wifi_ssid}";
const char* wifiPassword = "{wifi_password}";

const char* mqttBroker = "broker.hivemq.com";
const int   mqttPort = 1883;
const char* mqttClientId = "{mqtt_client_id}";
const char* mqttTopic = "{mqtt_topic}";

WiFiClient   wifiClient;
PubSubClient mqttClient(wifiClient);

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

  mqttClient.publish(mqttTopic, "Hello World!");
  delay(5000);
}
