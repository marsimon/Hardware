#define SSerialTxControl 3   //TX컨트롤핀

#define RS485Transmit    HIGH
#define RS485Receive     LOW

#define Pin13LED         13

int byteReceived;
int byteSend;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SSerialTxControl, OUTPUT);

  digitalWrite(SSerialTxControl, RS485Transmit);  // 송신모드
  // Tx컨트롤을 이용해 수신받을지 발신할 지를 구분합니다.
  // 수신모드 - LOW
  // 발신모드 - HIGH
  Serial1.begin(115200);   // 보드레이트를 설정합니다.
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  Serial1.write(0x02);
  Serial1.write(0x16);
  Serial1.write(0x03);          // 데이터 전송
  delay(10);
    digitalWrite(LED_BUILTIN, LOW);

  delay(10000);
  
}
