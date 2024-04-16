#include "RTClib.h"

RTC_DS1307 RTC;

#define LED1 6 //6번이 12시 방향 LED연결 핀
#define LED2 7 //7번이 3시 방향
#define LED3 8 //8번이 6시 방향
#define LED4 9 //9번이 9시 방향 



void setup () { 

  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);

  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);

  Serial.begin(57600); // UART initialize 

  Wire.begin(); 

  RTC.begin(); 

//RTC.adjust(DateTime("Apr 16 2024","15:37:00")); // 현재시간을 설정

}

 

void loop () { 

  DateTime now = RTC.now(); 
  int h = now.hour()%12;
  Serial.println(h);
  if(h==11||h==0|h==1) {
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
  }

  else if(h==2||h==3|h==4) {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
  }

  else if(h==5||h==6|h==7) {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,HIGH);
    digitalWrite(LED4,LOW);
  }

  else {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,HIGH);
  }

  delay(10000); 

} 

