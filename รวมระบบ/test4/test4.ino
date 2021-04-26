#define Lamp1 3

const int analogInPin1 = A0;
const int relay = 2;

int sensorValue1 = 0; // ตัวแปรค่า Analog
int outputValue1 = 0; // ตัวแปรสำหรับ Map เพื่อคิด %

void setup()
{
  Serial.begin(9600);
  pinMode(Lamp1, OUTPUT);
}

void loop()
{
  sensorValue1 = analogRead(analogInPin1);
  outputValue1 = map(sensorValue1, 0, 1023, 100, 0);
  Serial.print("A0 = ");
  Serial.print(outputValue1);
  Serial.println(" %");
  //delay(600);
  if(outputValue1 < 50)
  {
    digitalWrite(Lamp1, HIGH);
    //if(digitalWrite(Lamp1) == HIGH)
    //  digitalWrite(Lamp1, LOW);
    //else
    //  digitalWrite(Lamp1, HIGH);
    Serial.print("ON");
    Serial.println(" ");
    //digitalWrite(Lamp1, LOW);
    delay(200);
  }
  else 
  {  
    digitalWrite(Lamp1, LOW);
    Serial.print("OFF");
    Serial.println(" ");
    delay(200);  
  }
}
