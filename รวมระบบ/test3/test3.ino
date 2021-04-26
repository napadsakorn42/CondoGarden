#include "DHT.h"
#define Lamp1 3
#define Lamp2 4
#define Lamp3 5
#define Lamp4 6

const int analogInPin1 = A0; //แคคตัส
const int analogInPin2 = A1; //พืชอวบน้ำ
const int analogInPin3 = A2; //เดหลี
const int analogInPin4 = A3; //เล็บครุฑ
const int relay = 2;

int sensorValue1 = 0; // ตัวแปรค่า Analog
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int outputValue1 = 0; // ตัวแปรสำหรับ Map เพื่อคิด %
int outputValue2 = 0;
int outputValue3 = 0;
int outputValue4 = 0;

DHT dht;

void setup()
{
  Serial.begin(9600);
  pinMode(Lamp1, OUTPUT);
  pinMode(Lamp2, OUTPUT);
  pinMode(Lamp3, OUTPUT);
  pinMode(Lamp4, OUTPUT);
}

void loop()
{
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (F)\t(C)");
  dht.setup(2); //data pin 2
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
  if(dht.toFahrenheit(temperature) >= 20 && dht.toFahrenheit(temperature) <= 36)
  {
    sensorValue1 = analogRead(analogInPin1);
    outputValue1 = map(sensorValue1, 0, 1023, 100, 0);
    Serial.print("A0 = ");
    Serial.print(outputValue1);
    Serial.println(" %");
    if(outputValue1 <= 70)
    {
      digitalWrite(Lamp2, HIGH);
      Serial.print("ON");
      Serial.println(" ");
      delay(1000);
    }
    else 
    {  
      digitalWrite(Lamp2, LOW);
      Serial.print("OFF");
      Serial.println(" ");
      delay(1000);
    }
    
    sensorValue2 = analogRead(analogInPin2);
    outputValue2 = map(sensorValue2, 0, 1023, 100, 0);
    Serial.print("A1 = ");
    Serial.print(outputValue2);
    Serial.println(" %");
    if(outputValue2 <= 10) 
    {
      digitalWrite(Lamp4, HIGH);
      Serial.print("ON");
      Serial.println(" ");
      delay(1000);
    }
    else 
    {  
      digitalWrite(Lamp4, LOW);
      Serial.print("OFF");
      Serial.println(" ");
      delay(1000);
    }
    
    sensorValue3 = analogRead(analogInPin3);
    outputValue3 = map(sensorValue3, 0, 1023, 100, 0);
    Serial.print("A2 = ");
    Serial.print(outputValue3);
    Serial.println(" %");
    if(outputValue3 <= 50) 
    {
      digitalWrite(Lamp1, HIGH);
      Serial.print("ON");
      Serial.println(" ");
      delay(1000);
    }
    else 
    {
      digitalWrite(Lamp1, LOW);
      Serial.print("OFF");
      Serial.println(" ");
      delay(1000);
    }
    sensorValue4 = analogRead(analogInPin4);
    outputValue4 = map(sensorValue4, 0, 1023, 100, 0);
    Serial.print("A3 = ");
    Serial.print(outputValue4);
    Serial.println(" %");
    if(outputValue4 <= 5) 
    {
      digitalWrite(Lamp3, HIGH);
      Serial.print("ON");
      Serial.println(" "); 
      delay(1000);
    }
    else 
    {
      digitalWrite(Lamp3, LOW);
      Serial.print("OFF");
      Serial.println(" ");
      delay(1000);
    }
  }
}
