const int analogInPin1 = A0;
const int analogInPin2 = A1;

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "yCVdtGhM264bOYAuKfq2t3Qo9gCv4-SK";
char ssid[] = "bansritrang super01";
char pass[] = "tawee12345";

/**void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}*/
int sensorValue1 = 0;        // ตัวแปรค่า Analog
int sensorValue2 = 0;
int outputValue;        // ตัวแปรสำหรับ Map เพื่อคิด %

void setup() {
  Serial.begin(9600);
}

void loop() {
    sensorValue1 = analogRead(analogInPin1);
    outputValue = map(sensorValue1, 0, 1023, 100, 0);
    Serial.print("A0 = ");
    Serial.print(outputValue);
    Serial.println(" %");
    sensorValue2 = analogRead(analogInPin2);
    outputValue = map(sensorValue2, 0, 1023, 100, 0);
    Serial.print("A1 = ");
    Serial.print(outputValue);
    Serial.println(" %");
    delay(1000); // ใช้จริงเปลี่ยน 1000 -> 6000 or 30000
}
