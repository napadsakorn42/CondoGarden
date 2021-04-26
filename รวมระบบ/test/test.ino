const int analogInPin1 = A0; //แคคตัส
const int analogInPin2 = A1; //พืชอวบน้ำ
const int analogInPin3 = A2; //เดหลี
const int analogInPin4 = A3; //เล็บครุฑ
const int relay = 2;

int sensorValue1 = 0;        // ตัวแปรค่า Analog
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int outputValue1 = 0;        // ตัวแปรสำหรับ Map เพื่อคิด %
int outputValue2 = 0;
int outputValue3 = 0;
int outputValue4 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void loop() {
  sensorValue1 = analogRead(analogInPin1);
  outputValue1 = map(sensorValue1, 0, 1023, 100, 0);
  Serial.print("A0 = ");
  Serial.print(outputValue1);
  Serial.println(" %");
  if(outputValue1 <= 70) {  //ตั้งค่า % ที่ต้องการจะรดน้ำต้นไม้
    digitalWrite(relay, HIGH);
    Serial.print("ON");
    Serial.println(" ");
    delay(1000);
  }
  else {  
    digitalWrite(relay, LOW);
    Serial.print("OFF");
    Serial.println(" ");
    delay(1000);
  }
//  delay(1000); // ใช้จริงเปลี่ยน 1000 -> 6000 or 30000
    
  sensorValue2 = analogRead(analogInPin2);
  outputValue2 = map(sensorValue2, 0, 1023, 100, 0);
  Serial.print("A1 = ");
  Serial.print(outputValue2);
  Serial.println(" %");
  if(outputValue2 <= 5) {
    digitalWrite(relay, HIGH);
    Serial.print("ON");
    Serial.println(" ");
    delay(1000);
  }
  else {  
    digitalWrite(relay, LOW);
    Serial.print("OFF");
    Serial.println(" ");
    delay(1000);
  }
//  delay(1000); // ใช้จริงเปลี่ยน 1000 -> 6000 or 30000
    
  sensorValue3 = analogRead(analogInPin3);
  outputValue3 = map(sensorValue3, 0, 1023, 100, 0);
  Serial.print("A2 = ");
  Serial.print(outputValue3);
  Serial.println(" %");
  if(outputValue3 <= 70) {
    digitalWrite(relay, HIGH);
    Serial.print("ON");
    Serial.println(" ");
    delay(1000);
  }
  else {  
    digitalWrite(relay, LOW);
    Serial.print("OFF");
    Serial.println(" ");
    delay(1000);
  }
//  delay(1000); // ใช้จริงเปลี่ยน 1000 -> 6000 or 30000
    
  sensorValue4 = analogRead(analogInPin4);
  outputValue4 = map(sensorValue4, 0, 1023, 100, 0);
  Serial.print("A3 = ");
  Serial.print(outputValue4);
  Serial.println(" %");
  if(outputValue4 <= 50) {  
    digitalWrite(relay, HIGH);
    Serial.print("ON");
    Serial.println(" ");
    delay(1000);
  }
  else {
    digitalWrite(relay, LOW);
    Serial.print("OFF");
    Serial.println(" ");
    delay(1000);
  }
//  delay(1000);
}
