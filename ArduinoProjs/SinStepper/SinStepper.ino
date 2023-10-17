#define PI 3.1416
#define BUTTON1 23
#define BUTTON2 24

#define EN 8 //스텝모터 활성화핀
#define STEP_DIR 7 //스텝모터 방향핀
#define STEP_STP 4 //스텝모터 스텝핀
#define STEP_END 11//스텝모터 엔드스위치

#define STEP_DELAY 200 //스텝모터 신호 주기. 스텝모터 속도가 부족할 경우 값을 더 감소 / 너무 줄이면 작동 X

#define VAR_REG1 A0 // 진폭1 가변저항
#define VAR_REG2 A1 // 주기1
#define VAR_REG3 A2 // 진폭2 
#define VAR_REG4 A3 // 주기2s
#define VAR_REG5 A4 // 기준점

//한바퀴에 4mm 이동, 바퀴당 200스텝, 1mm당 50스텝 
// 총 스트로크 280, 중간지점 140, 이동범위 +-60
// 주기 최소 2.5초, 최대 6초, 진폭 50~100

#define STEP_MID 140 //엔드 스위치로부터 가운데 지점까지의 스텝 (mm)
#define STEP_MAX 280 
unsigned long runningTime=0;
int amp1,cycle1,amp2,cycle2;
int med;
int pos=0;

void step(boolean dir, int steps)
{
  digitalWrite(STEP_DIR, dir);
  delay(1);
  for (int i = 0; i< steps*50; i++)
  {
    digitalWrite(STEP_STP, HIGH);
    delayMicroseconds(STEP_DELAY);
    digitalWrite(STEP_STP, LOW);
    delayMicroseconds(STEP_DELAY); // 안의 숫자를 늘리면 속도 감소
  }
}

void StepperInit() {
  while(true) {
    if (digitalRead(STEP_END) == LOW) { // 엔드 스위치를 만났는지 체크
      step(LOW,1);
      break; // 엔드 스위치를 만나면 역방향으로 한번 움직이고 이동 중지
    }
    step(HIGH,1); //엔드 스위치 방향을 바꾸려면 3칸 윗줄의 LOW,HIGH 서로 바꾸기 
  }
  pos=0;
}

void StepMed() {
  if(pos > STEP_MID + med) {
    step(LOW, pos - STEP_MID + med);
  }
  else {
    step(HIGH, STEP_MID + med - pos);
  }
}

void setup() {
  pinMode(BUTTON1,INPUT_PULLUP);
  pinMode(BUTTON2,INPUT_PULLUP);
  pinMode(STEP_DIR, OUTPUT); 
  pinMode(STEP_STP,OUTPUT);
  pinMode(EN, OUTPUT);  
  pinMode(STEP_END,INPUT_PULLUP);
  digitalWrite(EN,LOW);
  StepperInit();
}

void Mov1() {
  runningTime = millis();
  while(millis() - runningTime < 180000) 
  {
    int targetStep = STEP_MID + med + sin(((millis()- runningTime)/1000*2*PI)/cycle1/2.0f) * amp1; // 기본 주기 1초. cycle이 커질수록 주기 길어짐.
    if(targetStep > pos) {
      step(HIGH, STEP_MID + med - pos);
    }
    else {
      step(LOW,pos - STEP_MID + med );
    }
    pos = targetStep;
  }
}

void Mov2() {
  
  runningTime = millis();
  while(millis() - runningTime < 180000) 
  {
    int targetStep = STEP_MID + med + sin(((millis()- runningTime)/1000*2*PI)/cycle2/2.0f) * amp2; // 기본 주기 1초. cycle이 커질수록 주기 길어짐.
    if(targetStep > pos) {
      step(HIGH, STEP_MID + med - pos);
    }
    else {
      step(LOW,pos - STEP_MID + med );
    }
    pos = targetStep;
  }
}

void loop() {
  if(digitalRead(BUTTON1) == LOW) {
    amp1 = map(analogRead(VAR_REG1),0,1023,50,100); //amp가 진폭, cycle이 주기, med가 가운데 지점. 크기 수정을 위해서는 map함수 안의 1000, 2000처럼 마지막
    cycle1 = map(analogRead(VAR_REG2),0,1023,5,12); //값 2개가 조정되는 범위이므로 이 값을 수정해서 사용 됩니다. 
    med = map(analogRead(VAR_REG5),0,1023,-60,60);
    StepMed();
    Mov1();
  }
  if(digitalRead(BUTTON2) == LOW) {
    amp2 = map(analogRead(VAR_REG3),0,1023,50,100);
    cycle2 = map(analogRead(VAR_REG4),0,1023,5,12);
    med = map(analogRead(VAR_REG5),0,1023,-60,60);
    StepMed();
    Mov2();
  }
}