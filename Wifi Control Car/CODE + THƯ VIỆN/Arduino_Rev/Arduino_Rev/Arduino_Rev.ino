#include <SoftwareSerial.h>
#include "Motor.h"
//=====================================================
#define Rx 0
#define Tx 1
//======================================================
// MOTOR
#define MotorL_IN1 7
#define MotorL_IN2 8
#define MotorR_IN3 9
#define MotorR_IN4 11
//======================================================
#define LED_LEFT_PIN A0
#define LED_RIGHT_PIN A1
#define BUZZER_PIN A3
//======================================================
SoftwareSerial mySrl(Rx, Tx);
Motor Motr;
void setup() {
  Motr.Write_Pin(MotorL_IN1, MotorL_IN2, MotorR_IN3, MotorR_IN4);
  pinMode(MotorL_IN1, OUTPUT);
  pinMode(MotorL_IN2, OUTPUT);
  pinMode(MotorR_IN3, OUTPUT);
  pinMode(MotorR_IN4, OUTPUT);
  pinMode(LED_LEFT_PIN, OUTPUT);
  pinMode(LED_RIGHT_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  mySrl.begin(9600);
}
// ============================================
// ---------------- Function ------------------
  // Light_on : R_LO
  // Light_off : R_L0F
  // Buzzer_on : R_BZO
  // Buzzer_off : R_BZOF
  // Top_on : R_T
  // Botton_on : R_B
  // Left_on : R_L
  // Right_on : R_R
  // Stop : R_S
// ============================================
void loop() {
  if (mySrl.available())
  {
    String RxBuff = "";
    char chr;
    while (mySrl.available())
    {
      chr = mySrl.read();
      RxBuff = RxBuff + chr;
    }
    Serial.println(RxBuff);

    if ( RxBuff == "R_LO")
    {
      digitalWrite(LED_LEFT_PIN,HIGH);
      digitalWrite(LED_RIGHT_PIN,HIGH);
    } else if (RxBuff == "R_LOF")
    {
      digitalWrite(LED_LEFT_PIN,LOW);
      digitalWrite(LED_RIGHT_PIN,LOW);
    } else if (RxBuff == "R_BZO")
    {
      digitalWrite(BUZZER_PIN,HIGH);
    } else if (RxBuff == "R_BZOF")
    {
      digitalWrite(BUZZER_PIN,LOW);
    } else if (RxBuff == "R_T")
    {
      Motr.Forward(170, 0);
    } else if (RxBuff == "R_B")
    {
      Motr.Backward(170, 0);
    } else if (RxBuff == "R_L")
    {
      Motr.Left(170, 0);
    } else if (RxBuff == "R_R")
    {
      Motr.Right(170, 0);
    } else if (RxBuff == "R_S")
    {
      Motr.Stop();
    }
  }
  else
  {
    // Nothing
  }
}
