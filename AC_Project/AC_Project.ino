//import for servo
#include <Adafruit_TiCoServo.h>
#include <known_16bit_timers.h>
//import for temp
#include <OneWire.h>
#include <DallasTemperature.h>

//the port the temp is on
#define ONE_WIRE_BUS 2

//making some stuff to use
Adafruit_TiCoServo myservo;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int pressed = 0;

void setup() {
  Serial.begin(9600);
  // servo is pin 9
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
  //start checking temp
  sensors.begin();
  // put the servo at 0 (the start)
  myservo.write(0);
  // state value for the ac remote (0 not on / 1 is on)
  pressed = 0;
}

void loop() {
  //delay 5 second to check temp
  delay(5000);

  // start getting temo
  sensors.requestTemperatures(); // Send the command to get temperature readings
  // saving value to use
  float sensorValue =  sensors.getTempCByIndex(0);

  // if the ac is off
  if (pressed == 0) {
    if (sensorValue < 23) {
      // no need to turn on the AC
    }

    // temp is higher than the min ac temp
    if (sensorValue > 28) {
      // check temp
      Serial.println("Temperature When Turning AC On: ");
      Serial.println(sensors.getTempCByIndex(0));
      // turn on ac
      //servo pos to 40
      delay(500);
      myservo.write(40);
      // servo pos to 180
      delay(1500);
      myservo.write(180);
      //servo pos to 40
      delay(500);
      myservo.write(40);
      //set preset value
      pressed = 1;
      // wait 10-20 minutes
      // delay (900000);
    }

  }
  //if the ac is on
  else if (pressed == 1) {
    //check the temp is lower than the max
    if (sensorValue < 23) {
      //check temp
      Serial.println("Temperature When Turning AC Off: ");
      Serial.println(sensors.getTempCByIndex(0));
      // turn off ac
      //servo pos to 40
      delay(500);
      myservo.write(40);
      // servo pos to 180
      delay(1500);
      myservo.write(180);
      //servo pos to 40
      delay(500);
      myservo.write(40);
      //set preset value
      pressed = 0;
      //return to checking
    }
  }
  //check pressed
  if (pressed == 0) {
    //print temp
    Serial.println("Temperature With AC Off: ");
    Serial.println(sensors.getTempCByIndex(0));
  }
  else {
    //print temp
    Serial.println("Temperature With AC On: ");
    Serial.println(sensors.getTempCByIndex(0));
  }

}
