#include <Stepper.h>
#define STICK_PUSH_MS 4
#define STICK_VR_X A1
#define STICK_VR_Y A0
int ms,x,y;
// 회전각도 설정 = 2048:한바퀴(360도), 1024:반바퀴(180도)
const int stepsPerRevolution = 2048; //360도
Stepper myStepper(stepsPerRevolution,11,9,10,8);

void setup() {
  myStepper.setSpeed(18);  
  Serial.begin(9600);   
  pinMode(STICK_PUSH_MS, INPUT_PULLUP);  
}
void loop() {
  ms = digitalRead(STICK_PUSH_MS); //0,1
  x = analogRead(STICK_VR_X); //0~1023
  y = analogRead(STICK_VR_Y); //0~1023
  
  if(x>600){
    Serial.println("left");
    myStepper.step(stepsPerRevolution);
    delay(1000);
  }
  if(x<500){
    Serial.println("right");
    myStepper.step(-stepsPerRevolution);
    delay(1000);
  }
   
  
 
  
}
