#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App
// Go to the Project Settings (nut icon).
char auth[] = "BLINK AUTH TOKEN"; //ได้มาจาก email หลังจาก new project


char ssid[] = "WIFI_SSID";
char pass[] = "WIFI_PASSWORD";

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
