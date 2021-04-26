const int analogInPin1 = A0; //แคคตัส
const int analogInPin2 = A1; //พืชอวบน้ำ
const int analogInPin3 = A2; //เดหลี
const int analogInPin4 = A3; //เล็บครุฑ

int sensorValue1 = 0;        // ตัวแปรค่า Analog
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
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
    delay(1000); // ใช้จริงเปลี่ยน 1000 -> 6000 or 30000
    sensorValue2 = analogRead(analogInPin2);
    outputValue = map(sensorValue2, 0, 1023, 100, 0);
    Serial.print("A1 = ");
    Serial.print(outputValue);
    Serial.println(" %");
    delay(1000); // ใช้จริงเปลี่ยน 1000 -> 6000 or 30000
    sensorValue3 = analogRead(analogInPin3);
    outputValue = map(sensorValue3, 0, 1023, 100, 0);
    Serial.print("A2 = ");
    Serial.print(outputValue);
    Serial.println(" %");
    delay(1000); // ใช้จริงเปลี่ยน 1000 -> 6000 or 30000
    sensorValue4 = analogRead(analogInPin4);
    outputValue = map(sensorValue4, 0, 1023, 100, 0);
    Serial.print("A3 = ");
    Serial.print(outputValue);
    Serial.println(" %");
    delay(1000); // ใช้จริงเปลี่ยน 1000 -> 6000 or 30000
}
