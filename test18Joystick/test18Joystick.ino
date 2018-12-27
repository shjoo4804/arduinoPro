#define STICK_PUSH_MS 2
#define STICK_VR_X A1
#define STICK_VR_Y A0
int ms,x,y;
void setup() {
  Serial.begin(9600); 
  pinMode(STICK_PUSH_MS, INPUT_PULLUP);  // 디지털 입력 풀업모드로 설정

}
void loop() {
  ms = digitalRead(STICK_PUSH_MS); //0,1
  x = analogRead(STICK_VR_X); //0~1023
  y = analogRead(STICK_VR_Y); //0~1023
  Serial.print("MS: ");
  Serial.print(ms);
  Serial.print("\t"); 
  Serial.print("x: ");
  Serial.print(x); 
  Serial.print("\t"); 
  Serial.print("y: ");  
  Serial.println(y); 
  delay(300); 
}
