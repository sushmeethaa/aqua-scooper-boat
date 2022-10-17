 #include "CytronMotorDriver.h"
// Configure the motor driver.
CytronMD motor2(PWM_DIR, 12, 50); // PWM 2 = Pin 9, DIR 2 = Pin 10.
// The setup routine runs once when you press reset.
void setup() {
    motor2.setSpeed(0);
}
// The loop routine runs over and over again forever.
void loop() {
  motor2.setSpeed(30);   // Motor 1 runs forward at 50% spee
}
