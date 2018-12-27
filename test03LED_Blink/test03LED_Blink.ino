#include <stdio.h>
#define TIME 500
#define LED1 2 // digital
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial setup()...");
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT); 
  pinMode(LED3, OUTPUT); 
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {
  Serial.println("Serial loop()...");
  digitalWrite(LED1,HIGH); // 1 == HIGH
  delay(TIME);
  digitalWrite(LED1,LOW);  // 0 == LOW
  digitalWrite(LED2,HIGH);
  delay(TIME);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,HIGH);
  delay(TIME);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,HIGH);
  delay(TIME);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,HIGH);
  delay(TIME);
  digitalWrite(LED5,LOW);
  delay(TIME);
  delay(TIME);
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH);
  digitalWrite(LED5,HIGH);
  delay(TIME);
  delay(TIME);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
  delay(TIME);
}
