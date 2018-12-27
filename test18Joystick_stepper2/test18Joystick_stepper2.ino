/*
  아두이노 기본 라이브러리는 단일 스탭모터
  구동만 지원한다.

  멀티스탭모터를 지원하는 액셀스탭퍼 라이브러리를 설치하자

  스케치>라이브러리포함>라이브러리 관리
  >검색 >AccelStepper> 설치
*/
#include <AccelStepper.h>
#define HALFSTEP 8  //Half-step mode (8 step control signal sequence)

// Motor pin definitions
#define mtrPin1  8     // IN1 on the ULN2003 driver 1
#define mtrPin2  9     // IN2 on the ULN2003 driver 1
#define mtrPin3  10     // IN3 on the ULN2003 driver 1
#define mtrPin4  11     // IN4 on the ULN2003 driver 1

#define mtrPin_1  4     // IN1 on the ULN2003 driver 2
#define mtrPin_2  5     // IN2 on the ULN2003 driver 2
#define mtrPin_3  6     // IN3 on the ULN2003 driver 2
#define mtrPin_4  7     // IN4 on the ULN2003 driver 2
#define STICK_PUSH_MS 2
#define STICK_VR_X A1
#define STICK_VR_Y A0
AccelStepper stepper1(HALFSTEP, mtrPin1, mtrPin3, mtrPin2, mtrPin4);
AccelStepper stepper2(HALFSTEP, mtrPin_1, mtrPin_3, mtrPin_2, mtrPin_4);

int speedLeft = 500;
int speedRight = 500;

int leftWheelForeward = 1;
int leftWheelBackward = -1;
int rightWheelForeward = -1;
int rightWheelBackward = 1;

char controlKey = 1;

int ms,x,y;

void setup() {
  Serial.println("setup()...");
  Serial.begin(9600);    
  pinMode(STICK_PUSH_MS, INPUT_PULLUP);  // 디지털 입력 풀업모드로 설정
  stepper1.setMaxSpeed(2000.0);
  stepper2.setMaxSpeed(2000.0); 
}

void loop() {
  ms = digitalRead(STICK_PUSH_MS); //0,1
  x = analogRead(STICK_VR_X); //0~1023
  y = analogRead(STICK_VR_Y); //0~1023

  if(x<100){//좌회전 전진
    Serial.print("x:");
    Serial.println(x);
    controlKey = 'a';
  }
  if(x>900){//우회전 전진
    Serial.print("x:");
    Serial.println(x);   
    controlKey = 'd';
  }
  if(y>900){//후진
    Serial.print("y:");
    Serial.println(y);   
    controlKey = 's';
  }
  if(y<100){//전진
    Serial.print("y:");
    Serial.println(y);   
    controlKey = 'w';
  }
  if(ms==0){  
    controlKey = '1';
  }
  switch (controlKey) {
    case 'w': //전진
      Serial.println(controlKey);
      stepper1.move(leftWheelForeward);
      stepper2.move(rightWheelForeward);
      stepper1.setSpeed(500);
      stepper2.setSpeed(500);
      stepper1.runSpeedToPosition();
      stepper2.runSpeedToPosition();
    
      if (controlKey == 's' || controlKey == 'a' || controlKey == 'd' || controlKey == '1' )
      {
        return;
      }
      break;
    case 's': //후진
      Serial.println(controlKey);
      stepper1.move(leftWheelBackward);
      stepper2.move(rightWheelBackward);
      stepper1.setSpeed(500);
      stepper2.setSpeed(500);
      stepper1.runSpeedToPosition();
      stepper2.runSpeedToPosition();
      
      if (controlKey == 'w' || controlKey == 'a' || controlKey == 'd' || controlKey == '1')
      {
        return;
      }
      break;
    case 'a': //좌회전 전진
      Serial.println(controlKey);
      stepper1.move(leftWheelForeward);
      stepper2.move(rightWheelForeward);
      stepper1.setSpeed(200);
      stepper2.setSpeed(600);
      stepper1.runSpeedToPosition();
      stepper2.runSpeedToPosition();
      if (controlKey == 'w' || controlKey == 's' || controlKey == 'd' || controlKey == '1')
      {
        return;
      }
      break;
    case 'd': //우회전 전진
      Serial.println(controlKey);
      stepper1.move(leftWheelForeward);
      stepper2.move(rightWheelForeward);
      stepper1.setSpeed(600);
      stepper2.setSpeed(200);
      stepper1.runSpeedToPosition();
      stepper2.runSpeedToPosition();
     
      if (controlKey == 'w' || controlKey == 's' || controlKey == 'a' || controlKey == '1' )
      {
        return;
      }
      break;
    
    case '1': //정지
      Serial.println(controlKey);
      stepper1.stop(); //motor stop
      stepper2.stop();
      stepper1.disableOutputs(); //motor power disconnect, so motor led will turn off
      stepper2.disableOutputs();
      controlKey = '0';
      Serial.println(controlKey);
      break;
    default :
      //controlKey = '1';
      break;
  }
}
