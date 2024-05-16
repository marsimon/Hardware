#include <Nextion.h>  


NexButton b1 = NexButton(0, 1, "b1");
NexButton b2 = NexButton(0, 2, "b2");
NexButton b3 = NexButton(0, 3, "b3");
NexButton b4 = NexButton(0, 4, "b4");
NexButton b5 = NexButton(0, 5, "b5");
NexButton b6 = NexButton(0, 6, "b6");
NexButton b7 = NexButton(0, 7, "b7");
NexButton b8 = NexButton(0, 8, "b8");
NexButton b9 = NexButton(0, 9, "b9");
NexButton b0 = NexButton(0, 10, "b10");
NexButton bk = NexButton(0, 11, "bk");
NexButton bd = NexButton(0, 12, "bd");

NexTouch *nex_listen_list[] = 
{
  &b1,
  &b2,
  &b3,
  &b4,
  &b5,
  &b6,
  &b7,
  &b8,
  &b9,
  &b0,
  &bk,
  &bd,  
  NULL
};  

int cfloor;

void UpdateFloor() {
  if(cfloor>999) {
    cfloor = cfloor % 1000;
  }
  Serial.print("text.val=");
  Serial.print(cfloor);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}

void b1PushCallback(void *ptr)  // Press event for button b1
{
  cfloor = cfloor * 10 + 2;
  UpdateFloor();
} 

void b2PushCallback(void *ptr)  
{
  cfloor = cfloor * 10 + 2;
  UpdateFloor();
} 
void b3PushCallback(void *ptr)  
{
  cfloor = cfloor * 10 + 3;
  UpdateFloor();
} 
void b4PushCallback(void *ptr)  
{
  cfloor = cfloor * 10 + 4;
  UpdateFloor();
} 
void b5PushCallback(void *ptr) 
{
  cfloor = cfloor * 10 + 5;
  UpdateFloor();
} 
void b6PushCallback(void *ptr)  
{
  cfloor = cfloor * 10 + 6;
  UpdateFloor();
} 
void b7PushCallback(void *ptr) 
{
  cfloor = cfloor * 10 + 7;
  UpdateFloor();
} 
void b8PushCallback(void *ptr) 
{
  cfloor = cfloor * 10 + 8;
  UpdateFloor();
} 
void b9PushCallback(void *ptr) 
{
  cfloor = cfloor * 10 + 9;
  UpdateFloor();
} 
void b0PushCallback(void *ptr) 
{
  cfloor = cfloor * 10;
  UpdateFloor();
} 
void bkPushCallback(void *ptr)  
{
  //힘 대 힘 
} 
void bdPushCallback(void *ptr)  
{
  cfloor = cfloor / 10;
  UpdateFloor();
} 

void setup() {  
  nexInit();
  Serial.begin(9600);


  b1.attachPush(b1PushCallback,&b1); 
  b2.attachPush(b2PushCallback,&b2); 
  b3.attachPush(b3PushCallback,&b3); 
  b4.attachPush(b4PushCallback,&b4); 
  b5.attachPush(b5PushCallback,&b5); 
  b6.attachPush(b6PushCallback,&b6); 
  b7.attachPush(b7PushCallback,&b7); 
  b8.attachPush(b8PushCallback,&b8); 
  b9.attachPush(b9PushCallback,&b9); 
  b0.attachPush(b0PushCallback,&b0); 
  bk.attachPush(bkPushCallback,&bk); 
  bd.attachPush(bdPushCallback,&bd); 
}
//루프 파트
void loop() { 
  nexLoop(nex_listen_list);
} 

