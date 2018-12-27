#include <Servo.h>
#define PIN 7

int reg = 0;
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("setup()...");

  servo.attach(PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop()...");
  reg = analogRead(A0);
  Serial.println(reg); // 0~1023
  Serial.println(map(reg,0,1023,0,180));
  servo.write(map(reg,0,1023,0,180)); //0~180도
  delay(100);
  //servo.write(0);
  //delay(1000);
}
