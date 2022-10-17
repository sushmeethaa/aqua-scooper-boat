#define echoPin 5
#define trigPin 6
#include "CytronMotorDriver.h"
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// Configure the motor driver.
CytronMD motor1(PWM_DIR, 13, 49); // PWM 2 = Pin 9, DIR 2 = Pin 10.
// The setup routine runs once when you press reset.
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
   pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
   motor1.setSpeed(0);
   Serial.begin(9600);
}
// The loop routine runs over and over again forever.
void loop() {
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance<32){
     motor1.setSpeed(50);
  }
  else{
     motor1.setSpeed(0);
  }
}
