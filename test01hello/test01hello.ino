#include <stdio.h>
#define TIME 500
char msg[] = "shinshin";
char *user_name = "kim";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial setup()...");
}

void loop() {
  Serial.println(msg);
  Serial.print("Serial loop()...");
  Serial.print("\t");
  Serial.println(user_name);
  delay(TIME);
}
