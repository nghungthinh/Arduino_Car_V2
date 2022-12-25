//HEX_ADD   BUTTON
//FF38C7    OK
//FF18E7    UP
//FF4AB5    DOWN
//FF10EF    LEFT
//FF5AA5    RIGHT
//FFA25D    1
//FF629D    2
//FFE21D    3
//FF22DD    4
//FF02FD    5
//FFC23D    6
//FFE01F    7
//FFA857    8
//FF906F    9
//FF6897    *
//FF9867    0
//FFB04F    #

#include<IRremote.h>
#define B_OK 0xFF38C7
#define Button_1 0xFFA25D
#define Button_2 0xFF629D
#define Button_3 0xFFE21D
#define Button_4 0xFF22DD
#define B_Left 0xFF10EF
#define B_Right 0xFF5AA5
#define B_Forward 0xFF18E7
#define B_Backward 0xFF4AB5

//Define L298n Motor Driver pins.
#define in1 7
#define in2 8
#define in3 9
#define in4 11
#define PWMmotor1 5//ENA
#define PWMmotor2 6//ENB

//Led and Buzzer
#define LED1 A0
#define LED2 A1
#define BUZ A3

int Speed = 80;
int receiver = 12;
uint32_t Previous;
IRrecv irrecv(receiver);
decode_results signals;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); //enable input from IR receiver
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(PWMmotor1,OUTPUT);
  pinMode(PWMmotor2,OUTPUT);
  pinMode(LED1, OUTPUT); //Set the LED right pin.
  pinMode(LED2, OUTPUT); //Set the LED left pin.
  pinMode(BUZ, OUTPUT); //Set the Buzzer pin.
}

void loop(){
if(irrecv.decode(&signals)){
  Serial.println(signals.value, HEX);
  if(signals.value==0xFFFFFFFF){
    signals.value=Previous;
    }
  switch(signals.value){
  case Button_1: digitalWrite(BUZ, HIGH);break; 
  case Button_2: digitalWrite(LED1, HIGH); digitalWrite(LED2, HIGH);break;
  case Button_3: digitalWrite(A3,LOW);  digitalWrite(A1,LOW);  digitalWrite(A0,LOW); break;
  case B_Left: left(); break;
  case B_Right: right(); break;
  case B_Forward: forward(); break;
  case B_Backward: backward(); break;
  case B_OK: Stop(); break;
  }
  Serial.println (signals.value, HEX);//display Hex signals
  irrecv.resume();//get the next signal
  }
}
void buzzer(){
  digitalWrite(BUZ, HIGH);   // turn the BUZ on (HIGH is the voltage level)
  delay(5);
  digitalWrite(BUZ, LOW);   // turn the BUZ off (HIGH is the voltage level)
  delay(5);
  }
void lightRight(){
  digitalWrite(LED2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);
  digitalWrite(LED2, LOW);   // turn the LED off (HIGH is the voltage level)
  delay(10);
  }
void lightLeft(){
  digitalWrite(LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);
  digitalWrite(LED1, LOW);   // turn the LED off (HIGH is the voltage level)
  delay(10);
  }
void forward() {
  digitalWrite(PWMmotor1,HIGH);
  digitalWrite(PWMmotor2,HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in3, HIGH);
}

void backward() {
  digitalWrite(PWMmotor1,HIGH);
  digitalWrite(PWMmotor2,HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in4, HIGH);
}

void left() {
  digitalWrite(PWMmotor1,Speed);
  digitalWrite(PWMmotor2,Speed);
  digitalWrite(in3, Speed);
  digitalWrite(in2, Speed);
}

void right() {
  digitalWrite(PWMmotor1,Speed);
  digitalWrite(PWMmotor2,Speed);
  digitalWrite(in4, Speed);
  digitalWrite(in1, Speed);
}

void Stop() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}
