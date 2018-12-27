#include <stdio.h>
#define TIME 500
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial setup()...");
}

void loop() {
  Serial.println("Serial loop()...");
  for(int i=0; i<10; i++){
    Serial.print(i);
    delay(TIME);
  }
  Serial.print("\n");
}
