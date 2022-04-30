#include <Servo.h>

//CONSTANTS
const int swordSWITCHPIN = 2;
const int swordSERVOPIN = 3;

//VARIABLES
int swordValue;
Servo swordServo;

void setup() {
  swordServo.attach(swordSERVOPIN);
  swordServo.write(0);
  pinMode(swordSWITCHPIN, INPUT);
}

void loop() {
  swordValue = digitalRead(swordSWITCHPIN);
  if(swordValue == LOW){
    Serial.println("sword lifted");
    swordServo.write(180);
    delay(50);
  }
  else if(swordValue == HIGH){
    Serial.println("sword lowered");
    swordServo.write(0);
    delay(50);
  }
}
