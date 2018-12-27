#include <stdio.h>
#define TIME 1000
char cTemp;
//String userName = ""; // 문자 이어서 출력할 때

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial setup()...");
}

void loop() {
  String userName = ""; // 입력받은 문자만 출력
  Serial.println("Serial loop()...");
  while(Serial.available()) {
    cTemp = Serial.read();
    userName.concat(cTemp);
  }
  Serial.println(userName);
  delay(TIME);
  
}
