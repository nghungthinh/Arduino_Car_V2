#include "ESP8266WiFi.h"
#include <ESP8266WebServer.h>
ESP8266WebServer webServer(80);
//=========Biến chứa mã HTLM Website==//
const char MainPage[] PROGMEM = R"=====(
<!DOCTYPE html> 
  <html>
   <head> 
       <title>HOME PAGE</title> 
        <style>
          body {
            text-align:center;
          }
          h1 {color:#003399;}
          a {text-decoration: none;color:#FFFFFF;}
          .img_button
          {
            width: 50px;
            height: 50px;
          }
          .middle_button
          {
            width: 100%;
          }
          .bt_stopall{
            font-size: large;
            height:50px; 
            width:100px;    
            text-align: center;
            background-color:#ff0000;
            border-radius:100px;
            border: crimson;    
        }            
          .bt_left {
            height:50px; 
            width:100px; 
            text-align: center;
            color:white;
            background-color:#FF6600;
            border-radius:100px;
            border: crimson;    
        }
          .bt_right {
            height:50px; 
            width:100px; 
            text-align: center;
            color:white;
            background-color:#FF6600;
            border-radius:100px;
            border: crimson;    
        }
          .bt_top {
            height:50px; 
            width:100px; 
            margin:10px 0;
            text-align: center;
            align-items: center;
            background-color:#00FF00;
            border-radius:100px;
            border: crimson; 
          }
          .bt_bottom {
            height:50px; 
            width:100px; 
            margin:10px 0;
            text-align: center;
            background-color:#00FF00;
            border-radius:100px;
            border: crimson; 
        }

          .bt_ledon {
            height:50px; 
            width:100px; 
            margin:10px 0;
            background-color:#FF6600;
            border-radius:5px;}
          .bt_ledoff {
            height:50px; 
            width:100px; 
            margin:10px 0;
            background-color:#00FF00;
            border-radius:5px;}
          .bt_buzzon {
            height:50px; 
            width:100px; 
            margin:10px 0;
            background-color:#FF6600;
            border-radius:5px;}
          .bt_buzzoff {
            height:50px; 
            width:100px;
            margin:10px 0;
            background-color:#00FF00;
            border-radius:5px;}
        </style>
       <meta charset="UTF-8">
   </head>
   <body> 
    </script>
      <h1>ESP8266 CONTROL</h1> 
      <div>Bật Tắt LED</div>
      <div>
        <button class="bt_ledon"><a href="/bt_ledon">ON</a></button>
        <button class="bt_ledoff"><a href="/bt_ledoff">OFF</a></button>
      </div>
      <div>Bật Tắt Buzzer</div>
      <div class="middle_button">
        <button class="bt_buzzon"><a href="/bt_buzzon">ON</a></button>
        <button class="bt_buzzoff"><a href="/bt_buzzoff">OFF</a></button>
      </div>
      <div>
        <div><button class = "bt_top"><a href="/bt_top">FORWARD</a></button></div>
        <div>
            <button class="bt_left"><a href="/bt_left">LEFT</a></button>
            <button class="bt_stopall"><a href="/bt_stopall">STOP</a></button>
            <button class="bt_right"><a href="/bt_right">RIGHT</a></button>
        </div>
        <div><button class = "bt_bottom"><a href="/bt_bottom">BACKWARD</a></button></div>
      </div>
   </body> 
  </html>
)=====";
//===============================================
#define Rx 3
#define Tx 1
char* ssid = "Sinhvienhanboad";
char* pass = "hoilamgi";
#include <SoftwareSerial.h>
SoftwareSerial mySrl(Rx,Tx);
void setup() {
  Serial.begin(9600);
  mySrl.begin(9600);
//===============================================
// WiFi
  WiFi.begin(ssid,pass);
  Serial.print("Connecting");
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print("...");
  }
  Serial.println(WiFi.localIP());
  webServer.on("/",mainpage);
  webServer.on("/bt_ledon",Light_on);
  webServer.on("/bt_ledoff",Light_off);
  webServer.on("/bt_buzzon",Buzzer_on);
  webServer.on("/bt_buzzoff",Buzzer_off);
  webServer.on("/bt_left",Ar_left);
  webServer.on("/bt_right",Ar_right);
  webServer.on("/bt_top",Ar_top);
  webServer.on("/bt_bottom",Ar_bottom);
  webServer.on("/bt_stopall",Ar_Stop);
  webServer.begin();
}
void loop() {
  webServer.handleClient();
}
void mainpage(){
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void Light_on(){
  mySrl.print("R_LO");
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void Light_off(){
  mySrl.print("R_LOF");
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void Buzzer_on(){
  mySrl.print("R_BZO");
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void Buzzer_off(){
  mySrl.print("R_BZOF");
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void Ar_top(){
  mySrl.print("R_T");
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void Ar_bottom(){
  mySrl.print("R_B");
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void Ar_left(){
  mySrl.print("R_L");
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void Ar_right(){
  mySrl.print("R_R");
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void Ar_Stop(){
  mySrl.print("R_S");
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}