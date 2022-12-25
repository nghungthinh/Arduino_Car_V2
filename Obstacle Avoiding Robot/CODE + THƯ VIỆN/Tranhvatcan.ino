#include <Servo.h>          //Servo motor library. This is standard library
#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library

//our L298N control pins
const int LeftMotorForward = 7;
const int LeftMotorBackward = 8;
const int RightMotorForward = 9;
const int RightMotorBackward = 11;
//Led and Buzzer
#define LED2 A1
#define LED1 A0
#define BUZ A3
//sensor pins
#define trig_pin A5 //analog input 1
#define echo_pin A4 //analog input 2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;
int Speed = 50;
NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; //our servo name


void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
 
  servo_motor.attach(4); //our servo pin

  servo_motor.write(160);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  int distanceRight = 0;
  int distanceLeft = 0;
  if (distance <= 30){
    moveStop();
    delay(50);
    moveBackward();
    delay(70);
    moveStop();
    distanceRight = lookRight();
    distanceLeft = lookLeft();
    
    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward();
  }
    distance = readPing();
}

int lookRight(){  
  servo_motor.write(70);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int lookLeft(){
  servo_motor.write(70);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorForward, Speed);
    digitalWrite(RightMotorForward, Speed);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(BUZ, HIGH);   // turn the BUZ on (HIGH is the voltage level)
  delay(50);
  digitalWrite(BUZ, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(50);
  
  digitalWrite(LeftMotorBackward, Speed);
  digitalWrite(RightMotorBackward, Speed);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

void turnRight(){

  digitalWrite(LED2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);
  digitalWrite(LED2, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(50);
  
  digitalWrite(LeftMotorForward, Speed);
  digitalWrite(RightMotorBackward, Speed);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(200);
  
  digitalWrite(LeftMotorForward, Speed);
  digitalWrite(RightMotorForward, Speed);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 
  
  
}

void turnLeft(){

  digitalWrite(LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);
  digitalWrite(LED1, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(50);

  digitalWrite(LeftMotorBackward, Speed);
  digitalWrite(RightMotorForward, Speed);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(200);
  
  digitalWrite(LeftMotorForward, Speed);
  digitalWrite(RightMotorForward, Speed);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
