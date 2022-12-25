#ifndef LineTracking_h
#define LineTracking_h
#include "Arduino.h"

class Motor 
{
  public:
    uint8_t IN1, IN2, IN3, IN4;
  void Write_Pin(uint8_t IN_1, uint8_t IN_2, uint8_t IN_3, uint8_t IN_4)
  {
    IN1 = IN_1;
    IN2 = IN_2;
    IN3 = IN_3;
    IN4 = IN_4;
  }
  void Stop()
  {
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(MotorR_IN3, 0);
    analogWrite(IN3, 0);
  }
  void Forward(int SPEED_ORIGIN, int SPEED_DEC)
  {
    analogWrite(IN1, SPEED_ORIGIN-SPEED_DEC);
    analogWrite(IN2, 0);
    analogWrite(IN3, SPEED_ORIGIN-SPEED_DEC);
    analogWrite(IN4, 0);
  }
  void Backward(int SPEED_ORIGIN, int SPEED_DEC)
  {
    analogWrite(IN1, 0);
    analogWrite(IN2, SPEED_ORIGIN-SPEED_DEC);
    analogWrite(IN3, 0);
    analogWrite(IN4, SPEED_ORIGIN-SPEED_DEC);
  }
  void Right(int SPEED_ORIGIN, int SPEED_DEC)
  {
    analogWrite(IN1, SPEED_ORIGIN-SPEED_DEC);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, SPEED_ORIGIN-SPEED_DEC);
  }
  void Left(int SPEED_ORIGIN, int SPEED_DEC)
  {
    analogWrite(IN1, 0);
    analogWrite(IN2, SPEED_ORIGIN-SPEED_DEC);
    analogWrite(IN3, SPEED_ORIGIN-SPEED_DEC);
    analogWrite(IN4, 0);
  } 
  void Right_1side(int SPEED_ORIGIN, int SPEED_DEC){
    analogWrite(IN1, SPEED_ORIGIN-SPEED_DEC);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
  }
  void Left_1side(int SPEED_ORIGIN, int SPEED_DEC){
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, SPEED_ORIGIN-SPEED_DEC);
    analogWrite(IN4, 0);
  }
};
#endif