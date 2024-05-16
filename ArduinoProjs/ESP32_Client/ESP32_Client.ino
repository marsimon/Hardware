
#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

#include <FirebaseClient.h>

#define DEVICE_NO "1"

#define API_KEY "AIzaSyA3N0pctFrutd3FsAOuqosPrSoMkVCQlhs"

#define USER_EMAIL "simon5678@naver.com"
#define USER_PASSWORD "mars-1234"
#define DATABASE_URL "https://stockcontrol-1599f-default-rtdb.asia-southeast1.firebasedatabase.app/"

void printError(int code, const String &msg);

void asyncCB(AsyncResult &aResult);

int readMux(int channel);

DefaultNetwork network; // initilize with boolean parameter to enable/disable network reconnection

UserAuth user_auth(API_KEY, USER_EMAIL, USER_PASSWORD);

FirebaseApp app;

#include <WiFiClientSecure.h>
WiFiClientSecure ssl_client;

using AsyncClient = AsyncClientClass;

AsyncClient aClient(ssl_client, getNetwork(network));

RealtimeDatabase Database;

//MUX 선택을 위한 디지털 핀
const int s0 = 12;
const int s1 = 14;
const int s2 = 27;
const int s3 = 26;
//Mux 입력 아날로그 핀
const int SIG_pin = 34;

bool sensorValues[16]={false};

const char *ssid = "TastyWifi"; // 와이파이 SSID & Passwordx
const char *password = "mars1234";

const char *dir; 
const char *sendData;


void InitFirebase() {
  ssl_client.setInsecure();
  app.setCallback(asyncCB);
  initializeApp(aClient, app, getAuth(user_auth));

  // Waits for app to be authenticated.
  // For asynchronous operation, this blocking wait can be ignored by calling app.loop() in loop().
  unsigned long ms = millis();
  while (app.isInitialized() && !app.ready() && millis() - ms < 120 * 1000)
        ;
  app.getApp<RealtimeDatabase>(Database);
  Database.url(DATABASE_URL);
  dir = ("/"+app.getUid()+"/"+DEVICE_NO).c_str();
}

void setup() {
	Serial.begin(115200);
	Serial.println("ESP32 Simple web Start");
	Serial.println(ssid);

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW); 
  
	WiFi.begin(ssid, password);

	//접속 완료 하면
	while (WiFi.status() != WL_CONNECTED) {
	delay(1000);
	Serial.print(".");
	}
    
	Serial.print("Wifi IP: ");
	Serial.println(WiFi.localIP());  //Show ESP32 IP on serial

	delay(100); 

  InitFirebase();
  Serial.print("Init Succesful");

  bool status = Database.set<String>(aClient, dir,sendData);
    if (status)
        Serial.println("Set string is ok");
    else
        printError(aClient.lastError().code(), aClient.lastError().message());

  long long lastSensing = millis();

}


void loop() {

  app.loop();

  Database.loop();

  /*
  for(int i = 0; i < 16; i ++){
    if(readMux(i) > 512) 
      sensorValues[i] = true;
    else sensorValues[i] = false;
    delay(10); 
  }*/
  string result = "";
  for (int i = 0; i < 16; ++i) {
    result += sensorValues[i] ? "1" : "0";
  } 
  
  sendData = result.c_str();
  Serial.println(sendData);

  bool status = Database.set<String>(aClient, dir,sendData);
    if (status)
        Serial.println("Set string is ok");
    else
        printError(aClient.lastError().code(), aClient.lastError().message());
}

int readMux(int channel)  { 
  int controlPin[] = {s0, s1, s2, s3}; 
  int muxChannel[16][4]={ {0,0,0,0},  
  {1,0,0,0}, //channel 1 
  {0,1,0,0}, //channel 2 
  {1,1,0,0}, //channel 3 
  {0,0,1,0}, //channel 4 
  {1,0,1,0}, //channel 5 
  {0,1,1,0}, //channel 6 
  {1,1,1,0}, //channel 7 
  {0,0,0,1}, //channel 8 
  {1,0,0,1}, //channel 9 
  {0,1,0,1}, //channel 10 
  {1,1,0,1}, //channel 11 
  {0,0,1,1}, //channel 12 
  {1,0,1,1}, //channel 13 
  {0,1,1,1}, //channel 14 
  {1,1,1,1} //channel 15 
  }; 
  // 시그널 핀 4개 출력
  for(int i = 0; i < 4; i ++){ 
    digitalWrite(controlPin[i], muxChannel[channel][i]); 
  } 
  
  //read the value at the SIG pin 
  int val = analogRead(SIG_pin);  
  return val; 
} 

void asyncCB(AsyncResult &aResult)
{
    if (aResult.appEvent().code() > 0)
    {
        Firebase.printf("Event msg: %s, code: %d\n", aResult.appEvent().message().c_str(), aResult.appEvent().code());
    }

    if (aResult.isDebug())
    {
        Firebase.printf("Debug msg: %s\n", aResult.debug().c_str());
    }

    if (aResult.isError())
    {
        Firebase.printf("Error msg: %s, code: %d\n", aResult.error().message().c_str(), aResult.error().code());
    }
}

void printError(int code, const String &msg)
{
    Firebase.printf("Error, msg: %s, code: %d\n", msg.c_str(), code);
}