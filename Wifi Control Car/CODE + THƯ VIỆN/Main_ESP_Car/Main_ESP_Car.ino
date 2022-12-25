#define BLYNK_TEMPLATE_ID "TMPLAvu3tPBB"
#define BLYNK_DEVICE_NAME "Control Car"
#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define BLYNK_DEBUG
#define APP_DEBUG
#define USE_NODE_MCU_BOARD
#define Rx 3
#define Tx 1
#include "BlynkEdgent.h"
#include <SoftwareSerial.h>
SoftwareSerial mySrl(Rx, Tx);
int Left_button, Right_button, Forward_button, Backward_button, LED_button, Buzzer_button;
BlynkTimer timer;
void setup() {
  Serial.begin(9600);
  mySrl.begin(9600);
  BlynkEdgent.begin();
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
BLYNK_WRITE(V0) {
  Left_button = param.asInt();
  if (Left_button == 1) {
    mySrl.print("R_L");
  } else if (Left_button == 0) {
    mySrl.print("R_S");
  }
}
BLYNK_WRITE(V1) {
  Right_button = param.asInt();
  if (Right_button == 1) {
    mySrl.print("R_R");
  } else if (Right_button == 0) {
    mySrl.print("R_S");
  }
}
BLYNK_WRITE(V2) {
  Forward_button = param.asInt();
  if (Forward_button == 1) {
    mySrl.print("R_T");
  } else if (Forward_button == 0) {
    mySrl.print("R_S");
  }
}
BLYNK_WRITE(V3) {
  Backward_button = param.asInt();
  if (Backward_button == 1) {
    mySrl.print("R_B");
  } else if (Backward_button == 0) {
    mySrl.print("R_S");
  }
}
BLYNK_WRITE(V4) {
  LED_button = param.asInt();
  if (LED_button == 1) {
    mySrl.print("R_LO");
  } else if (LED_button == 0) {
    mySrl.print("R_LOF");
  }
}
BLYNK_WRITE(V5) {
  Buzzer_button = param.asInt();
  if (Buzzer_button == 1) {
    mySrl.print("R_BZO");
  } else if (Buzzer_button == 0) {
    mySrl.print("R_BZOF");
  }
}
void loop() {
  BlynkEdgent.run();
}