#include <Servo.h>

Servo myServo;  // Create a Servo object
int LDR1 = 2;   // LDR 1 connected to digital pin D2
int LDR2 = 3;   // LDR 2 connected to digital pin D3
int servoPin = 9;  // Servo motor control pin D9

void setup() {
  myServo.attach(servoPin);  // Attach the servo to pin 9
  myServo.write(90);  // Set the initial position of the servo to 90 degrees
  
  pinMode(LDR1, INPUT);  // Set LDR 1 pin as input
  pinMode(LDR2, INPUT);  // Set LDR 2 pin as input
  
  Serial.begin(9600);  // Initialize Serial communication at 9600 baud rate
  Serial.println("Setup complete. Servo set to 90 degrees.");
}

void loop() {
  int ldr1State = digitalRead(LDR1);  // Read boolean state from LDR 1
  int ldr2State = digitalRead(LDR2);  // Read boolean state from LDR 2
  
  // Debugging output to see the states of the LDRs
  Serial.print("LDR1 State: ");
  Serial.print(ldr1State);  // Output the state of LDR1
  Serial.print(" | LDR2 State: ");
  Serial.println(ldr2State);  // Output the state of LDR2
  
  // Check if LDR 1 detects light (HIGH)
  if (ldr1State == HIGH && ldr2State == LOW) {
   
    myServo.write(45);  // Move servo to 45 degrees
    Serial.println("LDR1 detected light. Servo moving to 45 degrees.");
  }
  // Check if LDR 2 detects light (HIGH)
  else if (ldr2State == HIGH && ldr1State == LOW) {
    myServo.write(135);  // Move servo to 135 degrees
    Serial.println("LDR2 detected light. Servo moving to 135 degrees.");
  }
  // If both or neither LDRs detect light, keep the servo at 90 degrees
  else {
    myServo.write(90);  // Keep the servo at 90 degrees
    Serial.println("Neither LDR or both LDRs detected light. Servo remains at 90 degrees.");
  }

  delay(100);  // Small delay to stabilize readings
}
