int up_button = 2;
int down_button = 4;
int left_button = 5;
int right_button = 3;
int start_button = 6;
int select_button = 7;
int joystick_button = 8;
int joystick_axis_x = A0;
int joystick_axis_y = A1;
int buttons[] = {up_button, down_button, left_button, right_button, start_button, select_button, joystick_button};

//아두이노에 연결된 버튼과 조이스틱의 연결 핀 정보 

void setup() {

  for (int i; i < 7; i++) {
   pinMode(buttons[i], INPUT);
   digitalWrite(buttons[i], HIGH);
  } //위에 아두이노에서 연결된 핀들을 INPUT 모드로 설정

  Serial.begin(9600); //PC와 시리얼 통신을 9600속도로 개시 

}

void loop() {

  if(!digitalRead(up_button)||!digitalRead(down_button)||!digitalRead(left_button)||!digitalRead(right_button)) {
    Serial.println("c");
  } //네가지 버튼 중 아무거나 눌렸을 시 시리얼로 "c" 출력. 

  Serial.print(analogRead(joystick_axis_x)); //x축 조이스틱 값 출력
  Serial.print(",");
  Serial.println(analogRead(joystick_axis_y));  //y축 조이스틱 값 출력
 }
