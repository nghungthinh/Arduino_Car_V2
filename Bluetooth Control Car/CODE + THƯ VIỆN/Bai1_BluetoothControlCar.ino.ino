//Define L298n Motor Driver pins.
  #define in1 7
  #define in2 8
  #define in3 9
  #define in4 11
//Led and Buzzer
  #define LED 13
  #define LED2 A1
  #define LED1 A0
  #define BUZ A3
boolean lightFront = false;
boolean horn = false;
int Speed = 152; //204; 0 - 255.
int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int command; //Int to store app command state.
int Turnradius = 0; //Set the radius of a turn, 0 - 255 Note:the robot will malfunction if this is higher than int Speed.
int brakeTime = 45;
int brkonoff = 1; //1 for the electronic braking system, 0 for normal.
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(LED1, OUTPUT); //Set the LED right pin.
  pinMode(LED2, OUTPUT); //Set the LED left pin.
  pinMode(BUZ, OUTPUT); //Set the Buzzer pin.
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop(); //Initialize with motors stoped.
  if (lightFront) {digitalWrite(LED1, HIGH); digitalWrite(LED2, HIGH);}
    if (!lightFront) {digitalWrite(LED1, LOW); digitalWrite(LED2, LOW);}
    //  if (lightLeft) {digitalWrite(LED2, HIGH); }//digitalWrite(light_BL, HIGH);}
    //  if (!lightLeft) {digitalWrite(LED2, LOW); }//digitalWrite(light_BL, LOW);}
    if (horn) {digitalWrite(BUZ, HIGH); delay(10); digitalWrite(BUZ, LOW);}
    if (!horn) {digitalWrite(BUZ, LOW);}
      switch (command) {
        case 'F':
          forward();
          break;
        case 'B':
          back();
          //buzzer();
          break;
        case 'L':
          left();
          lightLeft();
          //buzzer();
          break;
        case 'R':
          right();
          lightRight();
          //buzzer();
          break;
        case 'G':
          forwardleft();
          lightLeft();
          break;
        case 'I':
          forwardright();
          lightRight();
          break;
        case 'H':
          backleft();
          //buzzer();
          break;
        case 'J':
          backright();
          //buzzer();
          break;
        case '0':
          Speed = 100;
          break;
        case '1':
          Speed = 140;
          break;
        case '2':
          Speed = 153;
          break;
        case '3':
          Speed = 165;
          break;
        case '4':
          Speed = 178;
          break;
        case '5':
          Speed = 191;
          break;
        case '6':
          Speed = 204;
          break;
        case '7':
          Speed = 216;
          break;
        case '8':
          Speed = 229;
          break;
        case '9':
          Speed = 242;
          break;
        case 'q':
          Speed = 255;
          break;
       
        case 'W':lightFront = true;break;
        case 'w':lightFront = false;break;
  //      case 'U':lightLeft = true;break;
  //      case 'u':lightLeft = false;break;
        case 'V':horn = true;break;
        case 'v':horn = false;break;
      }
      Speedsec = Turnradius;
      if (brkonoff == 1) {
        brakeOn();
      } else {
        brakeOff();
      }
    }
  }

void forward() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speed);
}

void back() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speed);
}

void left() {
  analogWrite(in3, Speed);
  analogWrite(in2, Speed);
}

void right() {
  analogWrite(in4, Speed);
  analogWrite(in1, Speed);
}
void lightRight(){
  digitalWrite(LED2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);
  digitalWrite(LED2, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(10);
  }
void lightLeft(){
  digitalWrite(LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);
  digitalWrite(LED1, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(10);
  }
void buzzer(){
  digitalWrite(BUZ, HIGH);   // turn the BUZ on (HIGH is the voltage level)
  delay(10);
  digitalWrite(BUZ, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(10);
  }
void forwardleft() {
  analogWrite(in1, Speedsec);
  analogWrite(in3, Speed);
}
void forwardright() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speedsec);
}
void backright() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speedsec);
}
void backleft() {
  analogWrite(in2, Speedsec);
  analogWrite(in4, Speed);
}

void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}

void brakeOn() {
  //Here's the future use: an electronic braking system!
  // read the pushbutton input pin:
  buttonState = command;
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == 'S') {
      if (lastButtonState != buttonState) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, HIGH);
        delay(brakeTime);
        Stop();
      }
    }
    // save the current state as the last state,
    //for next time through the loop
    lastButtonState = buttonState;
  }
}

void brakeOff() {

}
