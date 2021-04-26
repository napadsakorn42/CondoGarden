#define Lamp1 2
#define Lamp2 3
#define Lamp3 4
#define Lamp4 5

char test ;
char L ;

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
//  Serial.print("Lamp : ");
  if(Serial.available())
  {
    L = Serial.read();
    if(L == 1)
    {
      if(Serial.available())
      {
        Serial.print("1 or 0 : ");
        test = Serial.read();
      }
      else if(test == '1')
      {
        digitalWrite(Lamp1, HIGH);
      }
      else if(test == '0')
      {
        digitalWrite(Lamp1, LOW);
      }      
    }
    
    else if(L == 2)
    {
      if(Serial.available())
      {
        Serial.print("1 or 0 : ");
        test = Serial.read();
      }
      else if(test == '1')
      {
        digitalWrite(Lamp1, HIGH);
      }
      else if(test == '0')
      {
        digitalWrite(Lamp1, LOW);
      }      
    }
    
    else if(L == 3)
    {
      if(Serial.available())
      {
        Serial.print("1 or 0 : ");
        test = Serial.read();
      }
      else if(test == '1')
      {
        digitalWrite(Lamp1, HIGH);
      }
      else if(test == '0')
      {
        digitalWrite(Lamp1, LOW);
      }      
    }
    
    else
    {
      if(Serial.available())
      {
        Serial.print("1 or 0 : ");
        test = Serial.read();
      }
      else if(test == '1')
      {
        digitalWrite(Lamp1, HIGH);
      }
      else if(test == '0')
      {
        digitalWrite(Lamp1, LOW);
      }      
    }
  }
}
