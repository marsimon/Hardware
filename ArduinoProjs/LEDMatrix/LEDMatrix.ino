#include <Adafruit_NeoPixel.h>

#define LED_PIN 6 //LED 연결핀
#define LED_COUNT 256
#define BTNP1 2 //버튼1 연결핀
#define BTNP2 3 //버튼2 연결핀
#define BTNP3 4 //버튼3 연결핀

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
int rainbow[12][3] = {{24,24,24},{45,45,45},{66,66,66},{87,87,87},{108,108,108},{129,129,129},{150,150,150},{171,171,171},{192,192,192},{213,213,213},{234,234,234},{255,255,255}};
int rainbow_c[12][3] = {{255,0,0},{255,127,0},{255,255,0},{127,255,0},{0,255,0},{0,255,127},{0,255,255},{0,127,255},{0,0,255},{127,0,255},{255,0,255},{255,0,127}};
const uint8_t gamma8[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };


int pinmap[16][16];
int prevrun = 0;
int running = 0;
int bright=0;
int bstep =0;

unsigned long nextrun=0;

void setup() {
  strip.begin();  
  strip.show();
  
  pinMode(BTNP1,INPUT);
  pinMode(BTNP2,INPUT);
  pinMode(BTNP3,INPUT);

  int cnt=0;
  for(int i=0;i<16;i++) {
    for(int j=15;j>=0;j--) {
      pinmap[i][j] = cnt++;
    }
    i++;
    for(int j=0;j<16;j++) {
      pinmap[i][j] = cnt++;
    }
  }

  start();
}

void clear() {
  for(int i=0;i<16;i++) {
    for(int j=0;j<16;j++) {
      if(pinmap[i][j]==-1) continue;
      strip.setPixelColor(pinmap[i][j], 0, 0, 0); 
    }
  }
  strip.show();
  delay(10);
}

void start() {
  for(int i=0;i<256;i++) {
    for(int j=6;j<10;j++) {
      for(int k=0;k<2;k++) {
        strip.setPixelColor(pinmap[j][k], i, i, i);
      }
    } 
    strip.show();
    delay(5); // 시작 시 LED 켜지는 속도 조절 
  }
  for(int j=5;j<11;j++) {
    for(int k=0;k<3;k++) {
      pinmap[j][k] = -1;
    }
  } 
}

void BTN1() {
  int temp;
  if(prevrun!=running) {
    prevrun = running;
    bright = 0;
    bstep = 0;
  }
  switch (bstep) {
    case 0 : case 1 :
      bright++;
      if(bright>511)  {
        bstep++;
        bright=0;
        temp = 0;
      }  
      else if(bright>255) temp = gamma8[511 - bright];
      else temp = gamma8[bright];
      delay(4); // 버튼 1의 1,2 번째 밝기 조절속도 조절 
      break;
    case 2 :
      bright++;
      if(bright>511) {
        bstep=0;
        bright=0;
        temp = 0;
      }
      else if(bright>255) temp = gamma8[511 - bright];
      else temp = gamma8[bright];
      delay(10); // 버튼 1의 3 번째 밝기 조절속도 조절 
      break;
  }
  for(int i=0;i<16;i++) {
    for(int j=0;j<16;j++) {
      if(pinmap[i][j]==-1) continue;
      strip.setPixelColor(pinmap[i][j], temp, temp, temp); 
    }
  }
  strip.show();
}

void BTN2() {
  if(prevrun!=running) {
    clear();
    prevrun = running;
    bstep=0;
  }
  if(nextrun > millis()) {
    delay(100);
    return;
  }
  for(int i=0;i<255;i++) {
    for(int j=0;j<16;j++) {
      if(pinmap[j][bstep]==-1) continue;
      strip.setPixelColor(pinmap[j][bstep], gamma8[i], gamma8[i], gamma8[i]); 
    }
    strip.show();
    delay(1);
  }
  bstep++;
  if(bstep==16) {
    bstep=0;
    nextrun = millis() + 5000;
    clear();
  }
}

void BTN3() {
  
  if(prevrun!=running) {
    prevrun = running;
  }

  for(int i=0;i<8;i++) {
    for(int j=0;j<16;j++) {
      if(pinmap[i][j]==-1) continue;
      int b = gamma8[rainbow[((j%12)+i)%12][0]];
      strip.setPixelColor(pinmap[i][j], b,b,b);
    }
  }
  for(int i=0;i<8;i++) {
    for(int j=0;j<16;j++) {
      if(pinmap[i+8][j]==-1) continue;
      int b = gamma8[rainbow[((j%12)+(7-i))%12][0]];
      strip.setPixelColor(pinmap[i+8][j],b,b,b);
    }
  }
  strip.show();
  int f[3];
  f[0] = rainbow[0][0];
  f[1] = rainbow[0][1];
  f[2] = rainbow[0][2]; 
  for(int i=0;i<11;i++) {
    rainbow[i][0] = rainbow[i+1][0];
    rainbow[i][1] = rainbow[i+1][1];
    rainbow[i][2] = rainbow[i+1][2];
  }
  rainbow[11][0] = f[0];
  rainbow[11][1] = f[1];
  rainbow[11][2] = f[2]; 
  
  delay(100);//버튼 3의 동작 딜레이 조절
}

void loop() {
  if(digitalRead(BTNP1)==HIGH) {
    running = 1;
  }
  else if(digitalRead(BTNP2)==HIGH) {
    running = 2;
  }
  else if(digitalRead(BTNP3)==HIGH) {
    running = 3;
  }

  switch (running) {
    case 0 : 
      break;
    case 1 : 
      BTN1();
      break;
    case 2 : 
      BTN2();
      break;
    case 3 : 
      BTN3();
      break;
  }
  
}
