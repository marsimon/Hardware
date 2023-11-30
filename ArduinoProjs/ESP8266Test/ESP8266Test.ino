#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid     = "TastyWifi";//WIFI 이름
const char* password = "mars1234";//WIFI 비밀번호

ESP8266WebServer server(80);

int seats[4]= {0,0,0,0}; // 좌석 상태. 0 현재 비어있음. 1 현재 예약됨. 2. 현재 비어있으나 누가 앉아있음. 
void setup(void){

  Serial.begin(115200);
  delay(1000);
  WiFi.disconnect();

  Serial.print("Connecting to ");

  Serial.println(ssid);

  WiFi.begin(ssid, password);

  Serial.println(WiFi.SSID());

  WiFi.setAutoConnect(true); //자동 접속 설정

  WiFi.setAutoReconnect(true); //자동 재접속 설정 

  WiFi.waitForConnectResult();

  Serial.println(WiFi.localIP());
  // 연결 완료 까지 대기

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  }

  Serial.println("");

  Serial.print("Connected to ");

  Serial.println(WiFi.SSID());

  Serial.print("IP address: ");

  Serial.println(WiFi.localIP());



  if (MDNS.begin("esp8266")) {

    Serial.println("MDNS responder started");

  }



  //접속별 동작 설정



  server.on("/", [](){
    server.send(200, "text/html", "<h1>Seat Reservation System</h1><h1>Seat 1 Status : </h1>"+String(seats[0])+"<a href=\"/no1\">Reserve</a><h1>Seat 2 Status : </h1><a href=\"/no2\"><h1>Reserve</h1></a>");

  });



  server.on("/no1", [](){//ON 으로 접속시 LED를 켭니다.

  });

  server.on("/no2", [](){//OFF 으로 접속시 LED를 끕니다.

  });

  server.on("/no3", [](){//OFF 으로 접속시 LED를 끕니다.

  });

  server.begin();

  Serial.println("HTTP server started");

}



void loop(void){
  
  server.handleClient();//클라이언트 접속을 관리합니다.

}

