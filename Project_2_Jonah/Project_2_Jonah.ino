#include <Servo.h>
const int servoPin = 8; // Servo pin
const int buttonPin = 9; // Pushbutton pin
const int ledPin = 2; //led pin
int buttonState = 0;
int directionState = 0;
Servo myservo;
int pos = 0;

void setup() {
  myservo.attach(8);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  buttonState = digitalRead(buttonPin);
  if (directionState == 0){
    if (buttonState == HIGH) {
      directionState = 1;
      for(pos = 0; pos < 180; pos += 1){
        myservo.write(pos);
        delay(10); // waits 15ms to reach the position
        digitalWrite(ledPin, HIGH);
    }
  }
} else if (directionState == 1) {
    if (buttonState == HIGH) {
      directionState = 0;

      for (pos = 180; pos>=1; pos -=1){
        myservo.write(pos);
        delay(10);
        digitalWrite(ledPin, LOW);
      }
    }
  }
}
