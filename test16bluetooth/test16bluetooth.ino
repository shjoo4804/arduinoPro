//2번핀과 3번핀 사용
//Google Player >> BLE Scanner App >> download 
//앱실행 >> 기기검색(HMSoft) >> 연결됨 >> 시리얼모니터상에 OK+CONN출력됨
//CUSTOM SERVICE >> N:Notifications활성화됨 >> R:시리얼모니터에서 텍스트전송 >>App에서 결과확인
//W:App에서 텍스트전송 시리얼모니터에서 결과확인
//연결해제 >> 시리얼모니터상에 OK+LOST출력됨
#include <SoftwareSerial.h> 

#define __MEGA2560__ 0                   //0: Uno, 1: Mega 2560

#if __MEGA2560__
#else
int blueTx=2;   
int blueRx=3;   
SoftwareSerial mySerial(blueTx, blueRx); 
#endif

#define BAUDRATE 9600                 //select 9600 or 115200 w.r.t module

void setup() 
{
  Serial.begin(BAUDRATE);   
  mySerial.begin(BAUDRATE); 
}
void loop()
{
  if (mySerial.available()) {       
    Serial.write(mySerial.read());  
  }
  if (Serial.available()) {         
    mySerial.write(Serial.read()); 
  }
}
