#include <AFMotor.h>

AF_DCMotor m1(1); // define motor 1 as m1
AF_DCMotor m2(2); // define motor 2 as m2
AF_DCMotor m3(3); // define motor 3 as m3
AF_DCMotor m4(4); // define motor 4 as m4

void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  Serial.println("Robojax Motor test!");

  // initial state of motors: turn off all motors
  m1.setSpeed(0);
  m2.setSpeed(0);
  m3.setSpeed(0);
  m4.setSpeed(0);
}

void loop() {
  Serial.println("All Motors FORWARD 100% speed");
  m1.run(FORWARD);
  m1.setSpeed(speed(100));
  m2.run(FORWARD);
  m2.setSpeed(speed(100));
  m3.run(FORWARD);
  m3.setSpeed(speed(100));
  m4.run(FORWARD);
  m4.setSpeed(speed(100));
  
  delay(3000);

  // Release all motors
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
  
  Serial.println("All Motors RELEASE");
  
  delay(3000); 

  Serial.println("=============");
}

/*
 * Convert percentage value (0 to 100%) to motor speed (0 to 255)
 * written by Ahmad Shamshiri on Feb 12, 2021
 */
int speed(int b) {
  return map(b, 0, 100, 0, 255);
}