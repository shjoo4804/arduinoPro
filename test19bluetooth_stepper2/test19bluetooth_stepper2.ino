//2번핀과 3번핀 사용
//Google Player >> BLE Scanner App >> download 
//앱실행 >> 기기검색(HMSoft) >> 연결됨 >> 시리얼모니터상에 OK+CONN출력됨
//CUSTOM SERVICE >> N:Notifications활성화됨 >> R:시리얼모니터에서 텍스트전송 >>App에서 결과확인
//W:App에서 텍스트전송 시리얼모니터에서 결과확인
//연결해제 >> 시리얼모니터상에 OK+LOST출력됨
#include <AccelStepper.h>
#include <SoftwareSerial.h>
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

#define __MEGA2560__ 0                   //0: Uno, 1: Mega 2560
#if __MEGA2560__
#else
int blueTx=2;   
int blueRx=3;   
SoftwareSerial mySerial(blueTx, blueRx); 
#endif

#define BAUDRATE 9600                 //select 9600 or 115200 w.r.t module


AccelStepper stepper1(HALFSTEP, mtrPin1, mtrPin3, mtrPin2, mtrPin4);
AccelStepper stepper2(HALFSTEP, mtrPin_1, mtrPin_3, mtrPin_2, mtrPin_4);

int speedLeft = 500;
int speedRight = 500;

int leftWheelForeward = 1;
int leftWheelBackward = -1;
int rightWheelForeward = -1;
int rightWheelBackward = 1;

char controlKey = 1;

void setup() {
  Serial.begin(BAUDRATE);   
  mySerial.begin(BAUDRATE); 
  
  stepper1.setMaxSpeed(2000.0);
  stepper2.setMaxSpeed(2000.0);
}
void loop(){
  if (mySerial.available()) {       
    Serial.write(mySerial.read());  
  }
  if (Serial.available()) {         
    mySerial.write(Serial.read()); 
  }
  switch (controlKey) {
    case 'w': //전진
      _Go();
      Serial.println(controlKey);
      //controlKey = '0';
      break;
    case 's': //후진
      _Back();
      Serial.println(controlKey);
      //controlKey = '0';
      break;
    case 'a': //좌회전 전진
      _Left();
      Serial.println(controlKey);
      //controlKey = '0';
      break;
    case 'd': //우회전 전진
      _Right();
      Serial.println(controlKey);
      //controlKey = '0';
      break;
    case 'q': //왼쪽 제자리 회전
      _Left360();
      Serial.println(controlKey);
      //controlKey = '0';
      break;
    case 'e': //오른쪽 제자리 회전
      _Right360();
      Serial.println(controlKey);
      //controlKey = '0';
      break;
    case '1': //정지
      stepper1.stop(); //motor stop
      stepper2.stop();
      stepper1.disableOutputs(); //motor power disconnect, so motor led will turn off
      stepper2.disableOutputs();
      controlKey = '0';
      Serial.println(controlKey);
      break;
    default :
      controlKey = mySerial.read();
      break;
  }
}
void _Go() {  //foreward
  for (;;) {
    stepper1.move(leftWheelForeward);
    stepper2.move(rightWheelForeward);
    stepper1.setSpeed(500);
    stepper2.setSpeed(500);
    stepper1.runSpeedToPosition();
    stepper2.runSpeedToPosition();
    //delay(10);
    controlKey = mySerial.read();
    if (controlKey == 's' || controlKey == 'a' || controlKey == 'd' || controlKey == '1' || controlKey == 'q' || controlKey == 'e')
    {
      return;
    }
  }
}

void _Back() { //Backward
  for (;;) {
    stepper1.move(leftWheelBackward);
    stepper2.move(rightWheelBackward);
    stepper1.setSpeed(500);
    stepper2.setSpeed(500);
    stepper1.runSpeedToPosition();
    stepper2.runSpeedToPosition();
    //delay(10);
    controlKey = mySerial.read();
    if (controlKey == 'w' || controlKey == 'a' || controlKey == 'd' || controlKey == '1' || controlKey == 'q' || controlKey == 'e')
    {
      return;
    }
  }
}

void _Left() { //Left ForeWard
  for (;;) {
    stepper1.move(leftWheelForeward);
    stepper2.move(rightWheelForeward);
    stepper1.setSpeed(200);
    stepper2.setSpeed(600);
    stepper1.runSpeedToPosition();
    stepper2.runSpeedToPosition();
    //delay(10);
    controlKey = mySerial.read();
    if (controlKey == 'w' || controlKey == 's' || controlKey == 'd' || controlKey == '1' || controlKey == 'q' || controlKey == 'e')
    {
      return;
    }
  }
}

void _Right() { //Right ForeWard
  for (;;) {
    stepper1.move(leftWheelForeward);
    stepper2.move(rightWheelForeward);
    stepper1.setSpeed(600);
    stepper2.setSpeed(200);
    stepper1.runSpeedToPosition();
    stepper2.runSpeedToPosition();
    //delay(10);
    controlKey = mySerial.read();
    if (controlKey == 'w' || controlKey == 's' || controlKey == 'a' || controlKey == '1' || controlKey == 'q' || controlKey == 'e')
    {
      return;
    }
  }
}

void _Left360() { //Left Quick Trun
  for (;;) {
    stepper1.move(leftWheelBackward);
    stepper2.move(rightWheelForeward);
    stepper1.setSpeed(500);
    stepper2.setSpeed(500);
    stepper1.runSpeedToPosition();
    stepper2.runSpeedToPosition();
    //delay(10);
    controlKey = mySerial.read();
    if (controlKey == 'w' || controlKey == 's' || controlKey == 'd' || controlKey == '1' || controlKey == 'a' || controlKey == 'e')
    {
      return;
    }
  }
}

void _Right360() { //Right Quick Trun
  for (;;) {
    stepper1.move(leftWheelForeward);
    stepper2.move(rightWheelBackward);
    stepper1.setSpeed(500);
    stepper2.setSpeed(500);
    stepper1.runSpeedToPosition();
    stepper2.runSpeedToPosition();
    //delay(10);
    controlKey = mySerial.read();
    if (controlKey == 'w' || controlKey == 's' || controlKey == 'd' || controlKey == '1' || controlKey == 'q' || controlKey == 'a')
    {
      return;
    }
  }
}
