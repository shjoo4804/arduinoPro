#include <SimpleTimer.h>

#include <stdio.h>
// https://github.com/schinken/SimpleTimer
// >> zip으로 download >> 스케치 >> 라이브러리 포함하기

// 인터벌 : 설정한 시간마ㅏ다 돌림

SimpleTimer timer;
int count=0;
void setup() {
  Serial.begin(9600);
  Serial.println("setup()...test13SimpleTimer");
  timer.setInterval(3000, plus);
  timer.setInterval(5000, minus);
}

void plus() { 
  Serial.println("plus");
  count++;
}
void minus() {
  Serial.println("minus");
  count--;
}


void loop() {
  Serial.print(count);
  Serial.println(" loop()... ");
  timer.run();
  delay(1000);
  }
