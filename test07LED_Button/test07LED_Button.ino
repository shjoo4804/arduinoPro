#include <stdio.h>
#define TIME 1000
#define BUTTON 7
#define LED 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("setup()...");

  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // String userName = ""; // 루프 돌면서 초기화
  Serial.println("loop()...");
  Serial.println(digitalRead(BUTTON));
  if(digitalRead(BUTTON)==1) { // digitalRead(BUTTON) 로만 조건식줘도 됨
    Serial.println("LED ON");
    digitalWrite(LED, HIGH);
  }
  else {
    Serial.println("LED OFF");
    digitalWrite(LED, LOW);
  }
  delay(TIME);
  
}
