#include <SPI.h>              // We use this library, so it must be called here.
#include <MCP23S17.h>         // Here is the new class to make using the MCP23S17 easy.

MCP chip0(0, 8);//CS_Pin=8
MCP chip1(0, 9);//CS_Pin=9

static int delay_time=100;

void setup() {
  chip0.begin();//setup chip0
  chip1.begin();//setup chip1

  chip0.pinMode(0x0000);//set all port output
  chip1.pinMode(0x0000);

  //chip0.digitalWrite(0xff);
  
  /*
  for (int i = 1; i <= 16; i++) {
    chip0.pinMode(i, HIGH);//LOW=input,HIGH=output
    chip1.pinMode(i, HIGH);
  }*/
}

void loop() {
  /* //WAVE
  for (int i = 1; i <=16; i++) {
    chip0.digitalWrite(i, HIGH); // write the output chip in bit-mode, using our variable "value" as the argument for bit "i"
    delay(delay_time);
  }
  for (int i = 1; i <=16; i++) {
    chip0.digitalWrite(i, LOW); // write the output chip in bit-mode, using our variable "value" as the argument for bit "i"
    delay(delay_time);
  }
    for (int i = 1; i <=16; i++) {
    chip1.digitalWrite(i, HIGH); // write the output chip in bit-mode, using our variable "value" as the argument for bit "i"
    delay(delay_time);
  }
  for (int i = 1; i <=16; i++) {
    chip1.digitalWrite(i, LOW); // write the output chip in bit-mode, using our variable "value" as the argument for bit "i"
    delay(delay_time);
  } */
}
