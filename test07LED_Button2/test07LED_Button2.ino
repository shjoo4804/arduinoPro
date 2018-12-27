// mission1 >> Button 3개로 각각 R,G,B LED ON/OFF

#include <stdio.h>
#define TIME 1000
#define BUTTON_R 12
#define BUTTON_G 8
#define BUTTON_B 7
#define LED_R 4
#define LED_G 3
#define LED_B 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("setup()...");

  pinMode(BUTTON_R, INPUT);
  pinMode(BUTTON_G, INPUT);
  pinMode(BUTTON_B, INPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  Serial.println("loop()...");
  Serial.println(digitalRead(BUTTON_R));
  Serial.println(digitalRead(BUTTON_G));
  Serial.println(digitalRead(BUTTON_B));
  
  if(digitalRead(BUTTON_R)==1) { // digitalRead(BUTTON) 로만 조건식줘도 됨
    Serial.println("LED RED");
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
  }
  else if (digitalRead(BUTTON_G)==1) {
    Serial.println("LED GREEN");
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
  }
   else if (digitalRead(BUTTON_B)==1) {
    Serial.println("LED BLUE");
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
  }
  else {
    Serial.println("LED BLUE");
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
  }
  
  delay(TIME);
  
}
