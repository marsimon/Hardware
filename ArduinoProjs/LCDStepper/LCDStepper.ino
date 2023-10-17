/*

  ________________________________________________________________
   T6963c LCD PIN   |    LCD PIN NAME  |     MEGA 2560            |
  ________________________________________________________________|
          1         |          FG      |       GND                |
          2         |         GND      |       GND                |
          3         |         VDD      |       +5V                |
          4         |          VO      |  10K 가변저항 가운데 다리  |
          5         |          WR      |        17                |
          6         |          RD      |        18                |
          7         |       CE/CS      |        14                |
          8         |         C/D      |        15                |
          9번은 사용 X                  |
          10        |         RST      |        16                |
         11         |         DB0      |         8                |
         12         |         DB1      |         9                |
         13         |         DB2      |        10                |
         14         |         DB3      |        11                |
         15         |         DB4      |         4                |
         16         |         DB5      |         5                |
         17         |         DB6      |         6                |
         18         |         DB7      |         7                |
         19         |          FS      |       GND                |
         20         |         VEE      |   10K 가변저항 왼쪽 다리 |
         21         |       LED A      |        +5V               |
         22                 LED K               GND               |
  ________________________________________________________________|

  가변저항의 오른쪽 다리에는 GND 연결.
*/
#include "U8glib.h"
U8GLIB_T6963_240X128 u8g(8,  9, 10, 11,  4,  5,  6,  7,    14,         15,    17,    18,      16);   

#define BUTTON 23 //시작버튼핀 시작버튼핀과 엔드스위치 모두 다른 다리는 GND에 연결.

#define EN 20 //스텝모터 활성화핀
#define STEP_DIR 21 //스텝모터 방향핀
#define STEP_STP 22 //스텝모터 스텝핀

#define STEP_END 24//스텝모터 엔드스위치

#define CYCLE 3000// 한번 스텝모터 작동 후 다음 작동까지의 주기 (미리초)
#define STEPS 100 // 한번 작동 당 스텝 수 

 
//한바퀴당 200스

unsigned long begin =0;
unsigned long lastRun =0;
int time = 180;
bool running = false;

bool curDir = false;
int speed = 4; //스텝모터 속도, 값이 커질수록 속도 느려짐. 4가 가장 빠른값. 

void step(boolean dir, int steps)
{
  digitalWrite(STEP_DIR, dir);
  delay(100);
  for (int i = 0; i< steps; i++)
  {
    digitalWrite(STEP_STP, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP_STP, LOW);
    delay(speed); // 안의 숫자를 늘리면 속도 감소
  }
}

void draw(void) {
  u8g.setFont(u8g_font_6x10);
  String text = time / 60 + ":" + time%60;
  char ch[10]={0};
  text.toCharArray(ch,text.length()+1);
  u8g.drawStr( 0, 22,ch); //앞의 두 인수 : x,y 좌표 수정바람.
}

void StepperInit() {
  while(true) {
    if (digitalRead(STEP_END) == LOW) { // 엔드 스위치를 만났는지 체크
      step(LOW,1);
      break; // 엔드 스위치를 만나면 역방향으로 한번 움직이고 이동 중지
    }
    step(HIGH,1); //엔드 스위치 방향을 바꾸려면 73,76 번쨰 줄의 LOW,HIGH 서로 바꾸기 
  }
}

void setup() {
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(STEP_END,INPUT_PULLUP);
  pinMode(STEP_DIR, OUTPUT); 
  pinMode(STEP_STP,OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN,LOW);
  StepperInit();
}
void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(BUTTON)==LOW) {
    if(running == false) {
      begin = millis();
      running = true;
    }
  }
  if(running) {
    time = 180 - (millis() - begin) / 1000;
    if(time < 0) {
      time =180;
      running = false;
      lastRun = 0;
    }
    else {
      if((millis() - lastRun) > CYCLE) {
        step(curDir,STEPS);
        curDir = !curDir;
        lastRun = millis();
      }
    }
  }

  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(100);
}
