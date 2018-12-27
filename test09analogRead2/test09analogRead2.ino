//가변저항(rotary encoder)
//조도센서
//워터센서

#include <stdio.h>
#define TIME 500
#define LED 3 

int reg = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("setup()...");
}

void loop() {
  Serial.println("loop()...");
  reg = analogRead(A0);
  Serial.println(reg); // 0~1023
  //Serial.println(map(reg,0,1023,0,255)); // 0~1023 >>mapping>> 0~255
  //analogWrite(LED,map(reg,0,1023,0,255));
  delay(TIME);
}
