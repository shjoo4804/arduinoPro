#include <stdio.h>
#define TIME 1000
char cTemp;
String userName = ""; // 입력값을 전역변수에서 저장

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial setup()...");
}

void loop() {
  // String userName = ""; // 루프 돌면서 초기화
  Serial.println("Serial loop()...");
  if(Serial.available()) {
    userName = Serial.readString(); // 한번에 한 줄 받음
    // 입력받은 값으로 userName이 변경됨
  }
  Serial.println(userName);
  delay(TIME);
  
}
