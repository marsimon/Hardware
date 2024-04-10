#define OpenBtn 6
#define CloseBtn 9
#define RightBtn 7
#define LeftBtn 8
#define CHUpBtn 11
#define CHDownBtn 10
//PIR A7


void UpCH() {
  
  digitalWrite(CHUpBtn,HIGH);
  delay(200);
  digitalWrite(CHUpBtn,LOW);
  delay(150);
  digitalWrite(CHUpBtn,HIGH);
  delay(200);
  digitalWrite(CHUpBtn,LOW);
  delay(150);
}

void DownCH() {
  digitalWrite(CHDownBtn,HIGH);
  delay(200);
  digitalWrite(CHDownBtn,LOW);
  delay(150);
  digitalWrite(CHDownBtn,HIGH);
  delay(200);
  digitalWrite(CHDownBtn,LOW);
  delay(150);
}

void Open() {
  analogWrite(OpenBtn,255);
  delay(150);
  analogWrite(OpenBtn,0);
  delay(200);
  UpCH();
  analogWrite(OpenBtn,255);
  delay(150);
  analogWrite(OpenBtn,0);
  delay(200);
  DownCH();
  delay(34000);
}

void Close() {
  digitalWrite(CloseBtn,HIGH);
  delay(150);
  digitalWrite(CloseBtn,LOW);
  delay(200);
  UpCH();
  delay(150);
  digitalWrite(CloseBtn,HIGH);
  delay(150);
  digitalWrite(CloseBtn,LOW);
  delay(200);
  DownCH();
}



void setup() {
  Serial.begin(9600);
  pinMode(OpenBtn,OUTPUT);
  pinMode(CloseBtn,OUTPUT);
  pinMode(RightBtn,OUTPUT);
  pinMode(LeftBtn,OUTPUT);
  pinMode(CHUpBtn,OUTPUT);
  pinMode(CHDownBtn,OUTPUT);
  digitalWrite(OpenBtn,LOW);
  digitalWrite(CloseBtn,LOW);
  digitalWrite(RightBtn,LOW);
  digitalWrite(LeftBtn,LOW);
  digitalWrite(CHUpBtn,LOW);
  digitalWrite(CHDownBtn,LOW);
}

void loop() {
  // 열리는데 걸리는 시간 36초.
  if(Serial.available()>0) {
    Serial.readString();
    UpCH();

  }
}
