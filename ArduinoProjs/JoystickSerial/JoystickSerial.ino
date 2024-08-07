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


void setup() {

  for (int i; i < 7; i++) {
   pinMode(buttons[i], INPUT);
   digitalWrite(buttons[i], HIGH);
  }
  Serial.begin(9600);

}

void loop() {

  if(!digitalRead(up_button)||!digitalRead(down_button)||!digitalRead(left_button)||!digitalRead(right_button)) {
    Serial.println("c");
  }
  Serial.print(analogRead(joystick_axis_x));
  Serial.print(",");
  Serial.println(analogRead(joystick_axis_y));  
 }
