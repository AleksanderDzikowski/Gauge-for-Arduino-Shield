/*Plik zawierajacy ciała funkcji*/

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif

#include "Gauge.h"

OpAmp::OpAmp(){
  digitalPin = 9;
  valueResSet = 1.8;
  sourceVol = 9;
  maxVol = 5;
  bits = 1024;
  multiple = 11;
  perCent = 0;
  pwm = 10;
}

float OpAmp::GetCurrent(void){
  return curr;
}

float OpAmp::GetPower(void){
  return powerHead;
}

float OpAmp::GetNoFlipp(void){
  return volNoFlipp;
}

float OpAmp::GetVolOpAmp(void){
  return volOpAmpOut;
}

int OpAmp::GetPWM(void){
  return pwm;
}

float OpAmp::Voltage(uint8_t pin){

  int measure;
  static float voltage = 0;

  measure = analogRead(pin);
  //Serial.println(measure);
  //Serial.println(parts);
  voltage = measure * (5.0/1024.0);

  return voltage;
}

void OpAmp::Current(void){
  volResSet = Voltage(A0);
  //Serial.println(volResSet);
  curr = volResSet/valueResSet;
}

void OpAmp::PowerHead(void){
  static float diffVol;
  float volOpAmpOut = Voltage(A2);
  //Serial.println(volOpAmpOut);
  powerHead = (sourceVol - volOpAmpOut*(sourceVol/maxVol) )*curr;
}

void OpAmp::NoFlippIn(void){
  volNoFlipp = Voltage(A1);
}

void OpAmp::Fill_PerCent(){
  perCent = Serial.parseInt();
  if (perCent >= 0 && perCent <= 100) {
    pwm = map(perCent,0,100,0,255);
    analogWrite(digitalPin,pwm);
  }
}
