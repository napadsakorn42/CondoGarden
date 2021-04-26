const int analogInPin1 = A0; //แคคตัส

int sensorValue1 = 0;        // ตัวแปรค่า Analog
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
}
