//---------------------------------------------------------------
// DEFINE LINE TRACKING SENSORS
#define sensor_l 3
#define sensor_m 2
#define sensor_r 12
//---------------------------------------------------------------
// MOTOR
#define MotorL_IN1 7
#define MotorL_IN2 8
#define MotorR_IN3 9
#define MotorR_IN4 11
//---------------------------------------------------------------
// HC-SR04
#define trig_pin A5 
#define echo_pin A4 
//---------------------------------------------------------------
// SPEED MOTOR
#define SPEED 160
#include <C:\Users\Thinh\Desktop\Tracking_car\Motor.h>
#include "Arduino.h"
Motor Motr;
void setup() {
  Motr.Write_Pin(MotorL_IN1, MotorL_IN2, MotorR_IN3, MotorR_IN4);
  pinMode(sensor_l,INPUT);
  pinMode(sensor_m,INPUT);
  pinMode(sensor_r,INPUT);
  pinMode(MotorL_IN1, OUTPUT);
  pinMode(MotorL_IN2, OUTPUT);
  pinMode(MotorR_IN3, OUTPUT);
  pinMode(MotorR_IN4, OUTPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}
void loop() {
  // Avoider();
  Line_Tracking();
}
void Line_Tracking()
{
  int IR_L = digitalRead(sensor_l);
  int IR_M = digitalRead(sensor_m);
  int IR_R = digitalRead(sensor_r);
  if (IR_L == 1 && IR_M == 0 && IR_R == 0) {Motr.Left(SPEED, 40);} 
  if (IR_L == 0 && IR_M == 0 && IR_R == 1) {Motr.Right(SPEED, 0);}
  if (IR_L == 0 && IR_M == 1 && IR_R == 0) {Motr.Forward(SPEED, 0);}
  if (IR_L == 0 && IR_M == 1 && IR_R == 1) {Motr.Right(SPEED, 80);}
  if (IR_L == 1 && IR_M == 1 && IR_R == 0) {Motr.Left(SPEED, 80);}
}
void Avoider()
{
  int distance = Get_distance();
  delay(20);
  Serial.println(String(distance));
  if ( distance > 0 && distance <= 15) {
    Motr.Stop();
    delay(100);
    movetoAvoidObject(170,20);
  }
}
int Get_distance()
{
  int distance;
  unsigned long duration;
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig_pin,LOW);

  duration = pulseIn(echo_pin,HIGH);
  distance = int(duration/2/29.421);
  return distance;
}

void movetoAvoidObject(unsigned long SPEED_ORIGIN, unsigned long SPEED_DEC)
{
  //---------------------------------------------------
  Motr.Backward(150, 0);
  delay(100);
  Motr.Stop();
  delay(500);
  Motr.Right_1side(130, 20);
  delay(50);
  Motr.Stop();
  delay(500);
  Motr.Forward(140, 0);
  delay(800);
  Motr.Stop();
  delay(500);
  Motr.Left(150,0);
  delay(200);
  Motr.Stop();
  delay(500);
  Motr.Forward(140, 0);
  delay(300);
  Motr.Stop();
  delay(500);
  Motr.Left(150,0);
  delay(400);
  Motr.Stop();
  delay(500);
  while (digitalRead(sensor_l) == 0 && digitalRead(sensor_m) == 0 && digitalRead(sensor_r) == 0 )
  {
    Motr.Forward(170, 20);
  }
  Motr.Stop();
}