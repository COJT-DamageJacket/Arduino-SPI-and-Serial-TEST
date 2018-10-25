#include <SPI.h>              // We use this library, so it must be called here.
#include <MCP23S17.h>         // Here is the new class to make using the MCP23S17 easy.

MCP chip0(0, 8);//CS_Pin=8
MCP chip1(0, 9);//CS_Pin=9

int waiting = 0; //timer counter
int receive = 0; //receive data
int ledpin=13; //13 is builtin LED port in nano and UNO

void setup() {
  Serial.begin(9600);
  
  chip0.begin();//setup chip0
  chip1.begin();//setup chip1
  chip0.pinMode(0xffff);//set all port output
  chip1.pinMode(0xffff);
}

void loop() {
  if(Serial.available()>0){
    receive = Serial.read();
    if(receive==0){
      digitalWrite(ledpin,HIGH);
    }else{
      digitalWrite(ledpin,LOW);
    }
    chip0.digitalWrite(receive);
    //Serial.println(receive, BIN); //send converted data
    Serial.write(receive); //send raw data like echo
  }else{
    waiting++;
    if(waiting>50){
      waiting=0;
      Serial.write(receive); //0=.?
      //digitalWrite(ledpin,LOW); //turn off LED
    }
    delay(100);
  }
}
