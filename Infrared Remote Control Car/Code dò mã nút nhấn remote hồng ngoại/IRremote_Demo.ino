
/*Infrared Remote Controller & IR Receiver demo program
connect VS18838B to D12
*/

#include<IRremote.h>
int input_pin = 12;
IRrecv irrecv(input_pin);
decode_results signals;
void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); //enable input from IR receiver
}
void loop(){
if(irrecv.decode(&signals)){
  Serial.println(signals.value, HEX);
  irrecv.resume();//get the next signal
}
}
