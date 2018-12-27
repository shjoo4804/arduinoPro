#include <Stepper.h>
 
// 회전각도 설정 = 2048:한바퀴(360도), 1024:반바퀴(180도)
const int stepsPerRevolution = 2048; //360도
 
// 모터 드라이브에 연결된 핀 IN4, IN2, IN3, IN1 (핀연결 설정)
Stepper myStepper(stepsPerRevolution,11,9,10,8);
 
void setup() {
  myStepper.setSpeed(18);  //모터의 회전속도 설정1~18
  Serial.begin(9600);     //시리얼모니터
}
void loop() {
  // 시계 반대 방향으로 한바퀴 회전
  Serial.println("counterclockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);
 
  // 시계 방향으로 한바퀴 회전
  Serial.println("clockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}
