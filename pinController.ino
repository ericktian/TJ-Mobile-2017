/*The circuit:
RX is digital pin 10 (connect to TX of Xbee)
TX is digital pin 11 (connect to RX of Xbee)
Note:Not all pins on the Leonardo support change interrupts,
so only the following can be used for RX:8, 9, 10, 11, 14 (MISO), 
15 (SCK), 16 (MOSI).
*/
#include <SoftwareSerial.h>
#include <Servo.h>
//SoftwareSerial xbee(10, 11); // RX, TX
const int rb = 5;
const int lb = 7;

int buttonState;
int rbState;
int lbState;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial1.begin(9600);
    pinMode(rb, INPUT);
    digitalWrite(rb, HIGH);
    pinMode(lb, INPUT);
    digitalWrite(lb, HIGH);
    //internal pullup
    }
    void loop() { 
      // run over and over
      
      rbState = digitalRead(rb);
      lbState = digitalRead(lb);
      
      Serial.println(String(rbState) + " " + String(lbState));
      // Serial.println(buttonState);
      // Serial.println(String(bLFState) + " " + String(bLBState) 
      // + " " + String(bRFState) + " " + String(bRBState));
      delay(10);
      if (rbState == 0) 
      {
        Serial1.write('r');
      }
      else if (lbState == 0) 
      {
        Serial1.write('l');
        }
      else {
        Serial1.write('n');
      }
      
      
      }



