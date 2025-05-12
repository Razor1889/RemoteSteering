#include <Servo.h>

const int receiver_pin = 2;  // Channel 1 (joystick left-right) pin

const int SERVO_PIN = 9;     // Servo control pin

Servo motor;  // Servo motor object

unsigned long pulse_duration;  // To store pulse width

void setup() {
  Serial.begin(9600);  // Start serial communication
  motor.attach(SERVO_PIN);  // Attach the motor (servo) to the pin
  motor.write(90);  // Initial position (middle)
  
  pinMode(receiver_pin, INPUT);  // Set the receiver pin as input
}

void loop() {
  // Read the pulse duration (joystick position)
  pulse_duration = pulseIn(receiver_pin, HIGH);

  // Map the pulse duration to a range of 0 to 180 for servo movement
  // Assuming that pulse duration range is between 993 and 1985
  int mapped_value = map(pulse_duration, 993, 1985, 0, 180);

  // Write the mapped value to the servo (motor)
  motor.write(mapped_value);

  // Print the pulse duration and mapped servo angle to the Serial Monitor for debugging
  //Serial.print("Pulse Duration: ");
  //Serial.print(pulse_duration);
  //Serial.print("  Mapped Angle: ");
  //Serial.println(mapped_value);

  delay(100);  // Small delay for stability

  
}
