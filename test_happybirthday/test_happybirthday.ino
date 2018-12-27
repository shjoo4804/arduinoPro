#include <stdio.h>
#include "pitches.h"
#define SPEAKER 8 
#define BUTTON 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("setup()...");
  pinMode(BUTTON, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop()...");
  Serial.println(digitalRead(BUTTON));
  if(digitalRead(BUTTON)) { // digitalRead(BUTTON) 로만 조건식줘도 됨
    Serial.println("SPEAKER PLAY");
    tone(SPEAKER, NOTE_E3, 1000);
  }
  else {
    noTone(SPEAKER);
    
  }
  //tone(SPEAKER, NOTE_C3, 1000);
  
  delay(1000);
}
