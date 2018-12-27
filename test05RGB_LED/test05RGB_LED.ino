#include <stdio.h>
#define TIME 1000
#define RED 9
#define GREEN 10
#define BLUE 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial setup()...");
  randomSeed(analogRead(0)); // 랜덤 값 초기화
  //pinMode(RED, OUTPUT); // pwm(analog)은 pinMode를 적지않음
}

void loop() {
  Serial.println("Serial loop()...");
  //Serial.println(random(255)); // 랜덤 값 발생
  analogWrite(RED,random(255));
  analogWrite(GREEN,random(255));
  analogWrite(BLUE,random(255));
  delay(TIME);
  
}
