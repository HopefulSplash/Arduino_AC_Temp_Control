/* Stepper Motor Control */

#include <Stepper.h>
const int stepsPerRevolutionF = 280;
const int stepsPerRevolutionB = 2500;
// change this to fit the number of steps per revolution
// for your motor
// initialize the stepper library on pins 8 through 11:
Stepper myStepperF(stepsPerRevolutionF, 8, 9, 10, 11);
Stepper myStepperB(stepsPerRevolutionB, 8, 9, 10, 11);
void setup() {

   // set the speed at 60 rpm:
   myStepperF.setSpeed(60);
   myStepperB.setSpeed(60);
   // initialize the serial port:
   Serial.begin(9600);

      myStepperF.step(stepsPerRevolutionB);
   delay (3000);
}

void loop() {
   // step one revolution in one direction:
   Serial.println("clockwise");
  myStepperF.step(-stepsPerRevolutionF);
   delay(5000);
  // step one revolution in the other direction:
   Serial.println("counterclockwise");
   myStepperB.step(stepsPerRevolutionB);
   delay(1000);
}
