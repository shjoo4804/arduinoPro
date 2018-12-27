 // mission2 >> Button 3개로 RGB LED 각각 색깔 다르게 ON/OFF

#include <stdio.h>
#define TIME 1000
#define BUTTON_R 12
#define BUTTON_G 8
#define BUTTON_B 7
#define LED_R 9
#define LED_G 10
#define LED_B 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("setup()...");

  pinMode(BUTTON_R, INPUT);
  pinMode(BUTTON_G, INPUT);
  pinMode(BUTTON_B, INPUT);
  
}

void loop() {
 
  Serial.println("loop()...");
  Serial.println(digitalRead(BUTTON_R));
  Serial.println(digitalRead(BUTTON_G));
  Serial.println(digitalRead(BUTTON_B));
  
  if(digitalRead(BUTTON_R)==1) { // digitalRead(BUTTON) 로만 조건식줘도 됨
    Serial.println("LED RED");
    analogWrite(LED_R, 230);
    analogWrite(LED_G, 50);
    analogWrite(LED_B, 50);
  }
  else if (digitalRead(BUTTON_G)==1) {
    Serial.println("LED GREEN");
    analogWrite(LED_R, 50);
    analogWrite(LED_G, 230);
    analogWrite(LED_B, 50);
  }
   else if (digitalRead(BUTTON_B)==1) {
    Serial.println("LED BLUE");
    analogWrite(LED_R, 50);
    analogWrite(LED_G, 50);
    analogWrite(LED_B, 230);
  }
  else {
    Serial.println("LED OFF");
    analogWrite(LED_R, 0);
    analogWrite(LED_G, 0);
    analogWrite(LED_B, 0);
  }
  
  delay(TIME);
  
}
