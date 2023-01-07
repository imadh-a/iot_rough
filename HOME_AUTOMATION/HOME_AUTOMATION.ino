char val;         // variable to receive data from the serial port
int ledpin = 2;  // LED connected to pin 2 (on-board LED)

void setup()
{
  pinMode(ledpin = 2, OUTPUT); // pin 2 (on-board LED) as OUTPUT
  pinMode(ledpin = 3, OUTPUT); // pin 3 (on-board LED) as OUTPUT
  pinMode(ledpin = 4, OUTPUT); // pin 4 (on-board LED) as OUTPUT
  pinMode(ledpin = 5, OUTPUT); // pin 5 (on-board LED) as OUTPUT

  Serial.begin(9600);       // start serial communication at 9600bps
}

void loop()
{
  if ( Serial.available() )      // if data is available to read
  {
    
  
  val = Serial.read();         // read it and store it in 'val'
  Serial.println(val);
  if ( val == 'a' )              // if 'a' was received led 2 is switched off
  {
    digitalWrite(ledpin = 2, HIGH);    // turn Off pin 2
  }

  if ( val == 'b' )              // if 'A' was received led 2 on
  {
    digitalWrite(ledpin = 2, LOW);  // turn ON pin 2
  }

  if ( val == 'c' )              // if 'b' was received led 3 is switched off
  {
    digitalWrite(ledpin = 3, HIGH);    // turn Off pin 3
  }

  if ( val == 'd' )              // if 'B' was received led 3 on
  {
    digitalWrite(ledpin = 3, LOW);  // turn ON pin 3
  }

  if ( val == 'f' )              // if 'C' was received
  {

    digitalWrite(ledpin = 4, LOW);    // turn Off pin 4
  }

  if ( val == 'h' )              // if 'D' was received
  {

    digitalWrite(ledpin = 5, LOW);    // turn Off pin 5
  }


  if ( val == 'e' )              // if 'c' was received
  {
    digitalWrite(ledpin = 4, HIGH);    // turn On pin 4
  }
  if ( val == 'g' )              // if 'd' was received
  {
    digitalWrite(ledpin = 5, HIGH);    // turn ON pin 5
  }
  }
}
