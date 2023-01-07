#include<SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
#define LEDPIN 12
char tag[] = "5100940EC40F";
char input[12];
int count = 0;
boolean flag = 0;
void setup()
{ Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
}
void loop()
{
  if (mySerial.available())
  {
    count = 0;
    while (mySerial.available() && count < 12)
    {
      input[count] = mySerial.read();
      Serial.write(input[count]);
      count++;
      delay(5);
    }
    if (count == 12)
    {
      count = 0;
      flag = 1;
      while (count < 12 && flag != 0)
      {
        if (input[count] == tag[count])
          flag = 1;
        else
          flag = 0;
        count++;
      }
    }
    if (flag == 1)
    {
      Serial.println("Access Allowed!");
      digitalWrite(LEDPIN, HIGH);
      delay (2000);
      digitalWrite (LEDPIN, LOW);
    }
    else
    {
      Serial.println("Access Denied");
      digitalWrite(LEDPIN, LOW);
      delay(2000);
    }
    for (count = 0; count < 12; count++)
    {
      input[count] = 'F';
    }
    count = 0;
  }
}
