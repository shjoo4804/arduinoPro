#include <stdio.h>
#define TIME 1000

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial setup()...");
  randomSeed(analogRead(0)); // 랜덤 값 초기화
}

void loop() {
  Serial.println("Serial loop()...");
  Serial.println(random(255)); // 랜덤 값 발생
  delay(TIME);
  
}
