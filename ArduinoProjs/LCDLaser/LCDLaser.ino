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

#define BUTTON 23 //시작버튼핀

#define LASER1 20 //레이저 1
#define LASER2 21 //레이저 2

#define SENSOR1 A0 //광센서
#define SENSOR2 A1

const int val = 512; //광센서 감지 기준값.


#define BUZZ 22 //부저

int time = 180;
bool running = false;

void draw(void) {
  
  u8g.setFont(u8g_font_6x10);
  String text = time / 60 + ":" + time%60;
  char ch[10]={0};
  text.toCharArray(ch,text.length()+1);
  u8g.drawStr( 50, 100,ch); //앞의 두 인수 : x,y 좌표 수정바람.
}

void setup() {
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(LASER1, OUTPUT); 
  pinMode(LASER2,OUTPUT);
  pinMode(BUZZ, OUTPUT);
  digitalWrite(BUZZ,LOW);
}

void loop() {

  if(digitalRead(BUTTON)==LOW) {
    if(running == false) {
      running = true;
      time = 180;
      digitalWrite(LASER1,HIGH);
      digitalWrite(LASER2,HIGH);
    }
  }
  if(running) {
    if(time > 0) {
        time--;
        if(analogRead(SENSOR1) > val || analogRead(SENSOR2) > val) {
          digitalWrite(BUZZ,HIGH);
        }
         
    }
    else {
      time = 180;
      digitalWrite(LASER1,LOW);
      digitalWrite(LASER2,LOW);
      running = false;
    }
  }

  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(990);
}
