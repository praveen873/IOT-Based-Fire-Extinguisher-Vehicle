#include <Servo.h>

// Define the servo control pin
const int servoPin = 9; // You can use any PWM-capable pin

Servo myServo;

void setup() {
  // Attach the servo to the pin
  myServo.attach(servoPin);
}

void loop() {
  // Move the servo clockwise to 180 degrees
  myServo.write(180); // Move to 180 degrees towards left
  delay(2000);
  
  // Move the servo anticlockwise to 180 degrees
  myServo.write(0); // Move to 180 degrees towards right
  delay(2000);
}