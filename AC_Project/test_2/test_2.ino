#include <Servo.h>
   Servo myservo; // create servo object to control a servo

void setup() {
   myservo.attach(7); // attaches the servo on pin 9 to the servo object
      myservo.write(0);
}

void loop() {
   delay(1500);
   myservo.write(0);
   delay(1500);
   myservo.write(180); // sets the servo position according to the scaled value
 
}
