#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

#define MAX_XPOS 4 //위치 최댓값 정의
#define MAX_YPOS 950
#define MAX_ZPOS 130

const int enPin=8; //stepper enable

const int stepXPin = 2; //X.STEP
const int dirXPin = 5; // X.DIR
// dir핀에 HIGH신호 -> 시계방향 회전
const int stepYPin = 3; //Y.STEP
const int dirYPin = 6; // Y.DIR

const int stepZPin = 4; //Z.STEP
const int dirZPin = 7; // Z.DIR

const int stepAPin = 14; //A.STEP
const int dirAPin = 15; // A.DIR

const int limXPin = 9; //x축 엔드스위치
const int limYPin = 10; //y축 엔드스위치
const int limZPin = 11; //z축 엔드스위치

const int stepsPerRev=200; // 1회전당 스텝수

const int gearCount = 16; //기어 칸 수 
const int beltBlockLength = 2; //타이밍벨트 기어 1칸의 길이 (mm)
const float mmPerStepXY = (float)gearCount * beltBlockLength / stepsPerRev; //XY축 스텝당 이동거리

const int leadValue = 8; //리드스크류의 리드 값(mm)
const float mmPerStepZ = (float)leadValue/stepsPerRev; //Z축 스텝당 이동거리

const int pulseWidthMicros = 500; //스텝모터 펄스 신호 길이 (마이크로초) (0.5밀리초)
const int millisBtwnSteps = 4; //스텝모터 스텝간 주기 (밀리초) 이 변수 수정으로 속도 변경. 값을 줄일수록 빨라짐. 

//현재 포인터 위치 
float posX;
float posY;
float posZ;

int curSensorValue[21] = {0}; //센서 출력 값 저장 변수
int prevSensorValue[21] = {0}; //이전 센서 출력 값 저장 변수

void TCA9548A(uint8_t bus, uint16_t add){
  Wire.beginTransmission((int)add);  // TCA9548A address
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
}

void GetSensorValue() {
  //센서 20개의 값 측정. 출력 형식 ( 1,2,3,4,5,6,7,8,9,
  for(int i=0; i<20; i++) {
    prevSensorValue[i]=curSensorValue[i];
  }
  for(int i=0; i<7; i++) { 
    TCA9548A(i,0x70);
    delay(10);
    if (lightMeter.begin()) {
   
    }
    else {
    Serial.println(F("Error initialising BH1750"));
    }
    delay(20);
    curSensorValue[i] = (int)lightMeter.readLightLevel();
    Serial.println(curSensorValue[i]);
    delay(300);
  }
  for(int i=0; i<6; i++) { 
    TCA9548A(i,0x71);
    delay(10);
    if (lightMeter.begin()) {
      
    }
    else {
      Serial.println(F("Error initialising BH1750"));
    }
    delay(20);
    curSensorValue[i+7] = (int)lightMeter.readLightLevel();
    Serial.println(curSensorValue[i+7]);
    delay(300);
  }
  for(int i=0; i<7; i++) { 
    TCA9548A(i,0x72);
    delay(10);
    if (lightMeter.begin()) {
      
    }
    else {
      Serial.println(F("Error initialising BH1750"));
    }
    delay(20);
    curSensorValue[i+13] = (int)lightMeter.readLightLevel();
    Serial.println(curSensorValue[i+13]);
    delay(300);
  }  
}

void step_X(boolean dir, int steps)
{
  digitalWrite(dirXPin, dir);
  for (int i = 0; i< steps; i++)
  {
    digitalWrite(stepXPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepXPin, LOW);
    delayMicroseconds(800); // 안의 숫자를 늘리면 속도 감소
  }
}

void step_Y(boolean dir, int steps)
{
  digitalWrite(dirYPin, dir);
  for (int i = 0; i< steps; i++)
  {
    digitalWrite(stepYPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepYPin, LOW);
    delayMicroseconds(800); // 안의 숫자를 늘리면 속도 감소
  }
}

void step_Z(boolean dir, int steps)
{
  digitalWrite(dirZPin, dir);
  digitalWrite(dirAPin, dir);
  for (int i = 0; i< steps; i++)
  {
    digitalWrite(stepZPin, HIGH);
    digitalWrite(stepAPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepZPin, LOW);
    digitalWrite(stepAPin, LOW);
    delayMicroseconds(800); // 안의 숫자를 늘리면 속도 감소
  }
}




void InitStepper() {
  //스테퍼모터 위치 초기화 함수

  posX=0;
  posY=0;
  posZ=0;

 while(true) {
    if (digitalRead(limXPin) == LOW) { // 엔드 스위치를 만났는지 체크
      step_X(HIGH,30);
      break; // 엔드 스위치를 만나면 역방향으로 한번 움직이고 이동 중지
    }
    step_X(LOW,30); //엔드 스위치 방향을 바꾸려면 73,76 번쨰 줄의 LOW,HIGH 서로 바꾸기 
  }  

while(true) {
    if (digitalRead(limYPin) == LOW) { // 엔드 스위치를 만났는지 체크
      step_Y(HIGH,30);
      break; // 엔드 스위치를 만나면 역방향으로 한번 움직이고 이동 중지
    }
    step_Y(LOW,30); //엔드 스위치 방향을 바꾸려면 73,76 번쨰 줄의 LOW,HIGH 서로 바꾸기 
  }

 while(true) {
    if (digitalRead(limZPin) == LOW) { // 엔드 스위치를 만났는지 체크
      step_Z(LOW,30);
      break; // 엔드 스위치를 만나면 역방향으로 한번 움직이고 이동 중지
    }
    step_Z(HIGH,30); //엔드 스위치 방향을 바꾸려면 73,76 번쨰 줄의 LOW,HIGH 서로 바꾸기 
  } 

}


void MovX(int pos) {
  if(pos > MAX_XPOS||pos<0) return; //위칫값이 범위 밖이면 실행 안함. 

  float offset = pos - posX;
  int steps = offset / mmPerStepXY; //이동에 필요한 스텝 수 계산. 
  posX += steps * mmPerStepXY; //위치 값 업데이트

  if(steps > 0) 
    step_X(HIGH, steps);
  else {
    steps = -steps;
    step_X(LOW, steps);
    }
  
}

void MovY(int pos) {
  if(pos > MAX_YPOS||pos<0) return; //위칫값이 범위 밖이면 실행 안함. 

  float offset = pos - posY;
  int steps = offset / mmPerStepXY; //이동에 필요한 스텝 수 계산. 
  posY += steps * mmPerStepXY; //위치 값 업데이트

  if(steps > 0) 
    step_Y(HIGH, steps);
  else {
    steps = -steps;
    step_Y(LOW, steps);
    }
  
}

void MovZ(int pos) {
  if(pos > MAX_ZPOS||pos<0) return; //위칫값이 범위 밖이면 실행 안함. 

  float offset = pos - posZ;
  int steps = offset / mmPerStepZ; //이동에 필요한 스텝 수 계산. 
  posZ += steps * mmPerStepZ; //위치 값 업데이트

  if(steps > 0) 
    step_Z(LOW, steps);
  else {
    steps = -steps;
    step_Z(HIGH, steps);
    }  
}



void setup() {

  Serial.begin(9600);
  Wire.begin();

  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,HIGH); //LOW가 Enable

  pinMode(stepXPin,OUTPUT);
  pinMode(dirXPin,OUTPUT);

  pinMode(stepYPin,OUTPUT);
  pinMode(dirYPin,OUTPUT);
  
  pinMode(stepZPin,OUTPUT);
  pinMode(dirZPin,OUTPUT);

  pinMode(stepAPin,OUTPUT);
  pinMode(dirAPin,OUTPUT);

  pinMode(limXPin,INPUT_PULLUP);
  pinMode(limYPin,INPUT_PULLUP);
  pinMode(limZPin,INPUT_PULLUP);
  InitStepper();
}

void loop() {
 if(Serial.available()) {
    char buffer[50];
    int cnt = 0;
    unsigned long start = millis();
    while (millis() - start < 100) {
      if (Serial.available() < 1) {
        continue;
      }
      char data = Serial.read();
      if (data == '\n') {
        buffer[cnt++] = '\0';
        break;
      }
      buffer[cnt++] = data;
    }
    //시리얼 통신으로 들어온 데이터 한번에 읽어 버퍼에 저장
    int x,y,z;
    sscanf(buffer,"%d,%d,%d",&x,&y,&z);

   /* MovX(x);*/
    MovY(y);
    MovZ(z);
    
    GetSensorValue();
   }
}
