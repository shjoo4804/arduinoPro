#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7 
#define SEG_G 8
#define SEG_DP 9

byte digital[10][8] = {
  {0,0,0,0,0,0,1,1}, // 숫자0
  {1,0,0,1,1,1,1,0}, // 숫자1
  {0,0,1,0,0,1,0,1}, // 숫자2
  {0,0,0,0,1,1,0,0}, //3
  {1,0,0,1,1,0,0,1}, //4
  {0,1,0,0,1,0,0,0}, //5
  {0,1,0,0,0,0,0,1}, //6
  {0,0,0,1,1,1,1,0}, //7
  {0,0,0,0,0,0,0,1}, //8
  {0,0,0,0,1,0,0,0} //9
};

void setup() {
  Serial.begin(9600);
  Serial.println("setup()...test14sevenSegment");
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_DP, OUTPUT);
}

void loop() {
  Serial.println("loop...");
  int pin=2;
  for(int x=0; x<10; x++) {
    for(int i=0; i<8; i++){
      digitalWrite(pin+i, digital[x][i]);
    }
    delay(500);
  }
  delay(500);

}
