#include <stdio.h>
#define TIME 1000
int su;
//char su;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial setup()...");
}

void loop() {
  Serial.println("Serial loop()...");
  if(Serial.available()) {
    su = Serial.read();
    Serial.println(su);
    Serial.println((char)su);
    if(su=='1') {
      Serial.println("one");
    }
    if(su=='2') {
      Serial.println("two");
    }

    switch(su) {
      case 'a':
        Serial.println("aaa");
        break;
      case 'b':
        Serial.println("bbb");
        break;
      
    }
  }
  delay(TIME);
  
}
