#include <Servo.h>
const int trigger = 4;
const int echo = 3;

const int servo1 = 8;
const int servo2 = 9;

int timer = 0;
float distance = 0;
boolean open = false;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigger, LOW);
  //Serial.print("sent");

  timer = 0;
  while(digitalRead(echo) == LOW){
    delayMicroseconds(1);
    }
    
  while(digitalRead(echo) == HIGH){
    timer += 1;
    delayMicroseconds(1);
    //Serial.print(digitalRead(echo));
    }

  distance = (115/18)*timer*pow(10, -6)*343/2;
  Serial.print(distance, 2);
  Serial.print(" meters\n");
  
  if (distance < 0.23){
    if (open == false){
      digitalWrite(servo1, HIGH);
      digitalWrite(servo2, 0);
      delay(150);
      digitalWrite(servo1, LOW);
      digitalWrite(servo2, LOW);
      open = true;
      }
  }
    
  else{
    if (open == true){
      digitalWrite(servo1, 0);
      digitalWrite(servo2, HIGH);
      delay(150);
      digitalWrite(servo1, LOW);
      digitalWrite(servo2, LOW);
      open = false;
      }
    }
}
