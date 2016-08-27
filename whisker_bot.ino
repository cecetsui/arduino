//Import Servo Library
#include <Servo.h>

//Declare the pins for each whisker. Change accordingly
int left = 7;
int right = 5;
//Declare Servo types
Servo servoRight;
Servo servoLeft;
//Global variables that test which whisker is touched
int leftTouch;
int rightTouch;

//Set up the arduino
void setup() {
  //Set the pins up for the whiskerbot
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  //Attach the servo motors (my arduino is configured this way)
  servoRight.attach(12);
  servoLeft.attach(13);
  //Initially have bot go forward.
  forward();
  Serial.begin(9600);

}

//loop: runs continuously
void loop() {
  //Read to see if the whiskers has been touched/hit something
  leftTouch = digitalRead(left);
  rightTouch = digitalRead(right);
  //If both were touched
  if ((leftTouch == LOW) && (rightTouch == LOW)) {
    //Move back and just arbitrarily have it turn to the right
    backward(1000);
    turnRight(500);
  //If only the left was touched
  } else if (leftTouch == LOW) {
    //Move back and turn right
    backward(1000);
    turnRight(500);
  //If only the right was touched
  } else if (rightTouch == LOW) {
    //Move back and turn left
    backward(1000);
    turnLeft(500);
  }
  //After/otherwise, continue to go forward
  forward();
}

//Function: Sets arduino up to move forward. No delay here because the whisker both will continuously move forward until it hits something
void forward() {
  servoRight.writeMicroseconds(1300);
  servoLeft.writeMicroseconds(1700);
}

//Function: Sets arduino up to move backward
void backward(int t) {
  servoRight.writeMicroseconds(1700);
  servoLeft.writeMicroseconds(1300);
  delay(t); //delay for given amount of microseconds
}

//Function: Sets arduino up to turn right
void turnRight(int t) {
  servoRight.writeMicroseconds(1300);
  servoLeft.writeMicroseconds(1500);
  delay(t); //delay for given amount of microseconds
}

//Function: Sets arduino up to turn left
void turnLeft(int t) {
  servoRight.writeMicroseconds(1500);
  servoLeft.writeMicroseconds(1700);
  delay(t); //delay for given amount of microseconds
}

