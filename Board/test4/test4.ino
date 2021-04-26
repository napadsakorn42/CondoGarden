#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include "DHT.h"

const char *host = "http://maker.ifttt.com/trigger/Data/with/key/kKiOXsCLzUz41N8qLeQLFVtrRvZFzeLi41gmKJim6g";
const int analogInPin1 = A0;

int sensorValue1 = 0;
int outputValue;

DHT dht;

void setup() {
  Serial.begin(9600);
  Serial.println();
  WiFi.begin("AndroidAPDC76", "zvgs7152");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Waiting for connection");
  }
  dht.setup(2);
}

void loop() {
  delay(dht.getMinimumSamplingPeriod());
  float humidity = dht.getHumidity(); // ดึงค่าความชื้น
  float temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature), 1);
  
  sensorValue1 = analogRead(analogInPin1);
  outputValue = map(sensorValue1, 0, 1023, 100, 0);
  Serial.print("A0 = ");
  Serial.print(outputValue);
  Serial.println(" %");
  delay(1000);

  if(WiFi.status() == WL_CONNECTED) {
    StaticJsonBuffer[300] JSONbuffer;
    JsonObject& JSONencoder = JSONbuffer.createObject();
    JSONencoder["value1"] = humidity;
    JSONencoder["value2"] = temperature;
    JSONencoder["value3"] = outputValue;

    char JSONmessageBuffer[300];

    JSONencoder.prettyPrintTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
    Serial.println(JSONmessageBuffer);
    HTTPClient http;
    http.begin(host);
    http.addHeader("Content-Type", "application/json");

    int httpCode = http.POST(JSONmessageBuffer);
    String payload = http.getString();

    Serial.println(httpCode);
    Serial.println(payload);
    http.end();
  }
  delay(600000);
}
