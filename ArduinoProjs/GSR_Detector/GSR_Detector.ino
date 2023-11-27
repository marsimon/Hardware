const int GSR=A0;
int sensorValue=0;
int gsr_average=0;

bool isOn = true;

int GSR_VALUE =512; //GSR 센서의 기준값. 이 값보다 크면 거짓말로 판정함. 
#define LED_PIN 8 //LED 핀 
#define BUZZ_PIN 9 //부저 핀
#define BTN_PIN 10 //부저 핀

void getSensorVal() {
  long sum=0;
  for(int i=0;i<10;i++)
  {
  sensorValue=analogRead(GSR);
  sum += sensorValue;
  delay(5);
  }
  gsr_average = sum/10;
}

void setup(){
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
  pinMode(BUZZ_PIN,OUTPUT);
  pinMode(BTN_PIN,INPUT_PULLUP);
  digitalWrite(LED_PIN,LOW);
  long sum=0;
  for(int i=0;i<10;i++) 
  {      
      getSensorVal();
      sum += gsr_average;
  }
  GSR_VALUE = sum/10+20;
}


void loop(){
  if(digitalRead(BTN_PIN)==LOW) {
    isOn = !isOn;
    if(isOn==true) {
      long sum=0;
      for(int i=0;i<10;i++) {
        
        getSensorVal();
        sum += gsr_average;
      }
      GSR_VALUE = sum/10+20;
      Serial.println("기준값 : " +GSR_VALUE);
    }
    delay(200);
  }
  if(!isOn) return; 
  getSensorVal();
  Serial.println( gsr_average);
  if(gsr_average > GSR_VALUE) { 
    Serial.println("거짓말입니다. ");

    digitalWrite(LED_PIN,HIGH);
    tone(BUZZ_PIN, 523); 
    delay(500);
    
    digitalWrite(LED_PIN,LOW);
    noTone(BUZZ_PIN);
    delay(500);
  }
}