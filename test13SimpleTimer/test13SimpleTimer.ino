#include <SimpleTimer.h>

#include <stdio.h>
// https://github.com/schinken/SimpleTimer
// >> zip으로 download >> 스케치 >> 라이브러리 포함하기

SimpleTimer timer;
void setup() {
  Serial.begin(9600);
  Serial.println("setup()...test13SimpleTimer");
  timer.setTimeout(3000, testPrint); // 3초 후에 testPrint실행
}

void testPrint() { 
  Serial.println("testPrint()...good");
}

void loop() {
  Serial.println("loop()...1");
  timer.run();
  Serial.println("loop()...2");
  
  delay(1000);
}
