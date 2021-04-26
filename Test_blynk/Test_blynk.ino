#include <Blynk.h>
#define BLYNK_PRINT Serial
#include <BlynkESP8266.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "yCVdtGhM264bOYAuKfq2t3Qo9gCv4-SK";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "bansritrang super02";
char pass[] = "tawee12345";

void setup()
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
}
