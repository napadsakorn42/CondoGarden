#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"

const int analogInPin1 = A0;

char auth[] = "-WTkv_V5EpIbFwFoY6vj4mOZnv_OWx3a";
char ssid[] = "bansritrang super 02";
char pass[] = "tawee12345";

int sensorValue1 = 0;        // ตัวแปรค่า Analog
int outputValue;

//BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  Blynk.virtualWrite(V1, A0);
}

void loop() {
    sensorValue1 = analogRead(analogInPin1);
    outputValue = map(sensorValue1, 0, 1023, 100, 0);
    Serial.print("A0 = ");
    Serial.print(outputValue);
    Serial.println(" %");
    delay(1000); // ใช้จริงเปลี่ยน 1000 -> 6000 or 30000
}

//BLYNK_READ(V1) {
//  Blynk.virtualWrite(V1, val);
//}
