#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX | TX

void setup()
{

  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BT.begin(38400); // HC-05 default speed in AT command more
}

void loop()
{

  if (BT.available())
    Serial.write(BT.read());

  if (Serial.available())
    BT.write(Serial.read());
}
