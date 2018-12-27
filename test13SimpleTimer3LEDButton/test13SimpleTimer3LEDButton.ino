// 버튼 누르면 3초 후에 LED 켜짐

#include <SimpleTimer.h>
#include <stdio.h>

#define BUTTON 2
#define LED 8 

SimpleTimer timer;
int mState;

int count=0;
void setup() {
  Serial.begin(9600);
  Serial.println("setup()...test13SimpleTimer3LEDButton");
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  
}

void ledOn() { 
  Serial.println("ledOn......");
  digitalWrite(LED, HIGH);
  delay(1000);
  Serial.println("ledOff......");
  digitalWrite(LED, LOW);
  mState=0;
}

void loop() {
  Serial.println(count);
  //Serial.println(digitalRead(BUTTON));
  if(digitalRead(BUTTON) && mState==0){
    timer.setTimeout(3000,ledOn); // setTimeout
    Serial.println("Pressed Button..");
    mState=1;
  }
  timer.run();
  count++;
  delay(1000);
  
  
  }
