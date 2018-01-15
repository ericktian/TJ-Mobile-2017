/*The circuit:RX is digital pin 10 (connect to TX of Xbee)TX is digital pin 11 (connect to RX of Xbee)Note:Not all pins on the Leonardo support change interrupts,so only the following can be used for RX:8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).*/
#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial xbee(10, 11); 
// RX, TX

const int button1 = A5;


Servo myServoR;
Servo myServoL;
void setup() 
{// Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(13, OUTPUT);
  myServoR.attach(12);
  myServoL.attach(7);
  digitalWrite(button1,HIGH);
  }
void leftFlip(){
  // myServoL.write(15);
  // delay(100);
  myServoL.write(130); //165
  delay(20);
  myServoL.write(91);
}
void rightFlip(){
  // myServoR.write(165);
  // delay(100);
  myServoR.write(20);
  delay(20);
  myServoR.write(91);
  
}
void celebrate(){
  myServoR.write(165);
  myServoL.write(15);
  delay(5000);
  myServoR.write(91);
  myServoL.write(91);
}
void loop() 
{ // run over and over
  myServoR.write(91);
  myServoL.write(91);
  while (Serial1.available() > 0) 
  {

    char c = Serial1.read();
    // Serial.println(c);
    
    if (digitalRead(button1) == 0)
    {
      celebrate();
    }
    
    if (c == 'r') {
      rightFlip();
    }
    
    else if (c == 'l') {
      leftFlip();
    }
    
    delay(10);
 }
  
}
