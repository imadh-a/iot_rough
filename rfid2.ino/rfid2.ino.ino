#include<SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
#define LEDPIN 12
char tag[] ="510093E02A08";
// Replace with your own Tag ID
char input[12]; // 
int count = 0; //  A   counter   variable   to   navigate   through   the input[] character array
boolean flag = 0;

void setup()
{  Serial.begin(9600); //   
mySerial.begin(9600);
pinMode(LEDPIN,OUTPUT); 
}
void loop()
{
if(mySerial.available())

{
count = 0; // Reset the counter to zero

while(mySerial.available() && count < 12) 
{
input[count] = mySerial.read(); // 
Serial.write(input[count]);
count++; // increment counter
delay(5);
}
/* When the counter reaches 12 (the size of the ID) we stop and compare
each value 
of the input[] to the corresponding stored value */
if(count == 12) //
{
count =0; // reset counter varibale to 0
flag = 1;
/* Iterate through each value and compare till either the 12 values are 
all matching or till the first mistmatch occurs */
while(count<12 && flag !=0)  
{
if(input[count]==tag[count])
flag = 1; 

else
flag= 0; 

count++; // increment i
}
}
if(flag == 1)
{
Serial.println("Access Allowed!");
digitalWrite(LEDPIN,HIGH);
delay (2000);
digitalWrite (LEDPIN,LOW);
}
else
{
Serial.println("Access Denied");
digitalWrite(LEDPIN,LOW);
delay(2000);
}

for(count=0; count<12; count++) 
{
input[count]= 'F';
}
count = 0; // Reset counter variable
}
}
