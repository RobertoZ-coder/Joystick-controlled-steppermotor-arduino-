const int pinPul = 13;
 const int pinDir = 12;
 const int pinEna = 11;
 int xPin = A0;
 int xVal = 0;
 int xValMapped = 0;
int Direction=1;


void setup() {
  Serial.begin(9600);

  
  pinMode(pinPul,OUTPUT); 
  pinMode(pinDir,OUTPUT);
  pinMode(pinEna,OUTPUT);

   digitalWrite(pinEna, HIGH);
 digitalWrite(pinDir, LOW);

}

void loop() {
 xVal = analogRead(xPin);
xValMapped = map(xVal, 0, 1023, -100, 100);

if(xValMapped > -5 && xValMapped <5)
{
 delay(10);
  return;
;}



Direction=1;
if(xValMapped<0)
{
Direction=-1;
xValMapped= -xValMapped;
}

int snelheidDelay = map(xValMapped, 5, 100, 1000, 50);

if(Direction==1)
{
 digitalWrite(pinDir, LOW);
}
else
{
 digitalWrite(pinDir, HIGH);
}


/*
Serial.print("xVal=");
Serial.print(xVal);
Serial.print(" ,");
Serial.print(xValMapped);
Serial.print(" ,");
Serial.print(Direction);
Serial.println(); 
*/

digitalWrite(pinPul, HIGH);
delayMicroseconds(snelheidDelay);
digitalWrite(pinPul, LOW);
delayMicroseconds(snelheidDelay);



}
