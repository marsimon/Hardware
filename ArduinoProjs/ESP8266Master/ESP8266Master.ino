#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>


const char* ssid     = "TastyWifi";//WIFI 이름
const char* password = "mars1234";//WIFI 비밀번호

const char* address[4] = {"192.168.128.100", //슬레이브 기기들의 IP
"192.168.128.102",
"192.168.128.103",
"192.168.128.104"};
String redirect = "<html><head><meta http-equiv=\"refresh\" content=\"0; URL=/\" /></head><body>led</body></html>";
IPAddress ip(192,168,128,253);
IPAddress gateway(192, 168, 128,253);
IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(80);

int seats[4]= {0,0,0,0}; // 좌석 상태. (0 예약 X현재 비어있음.) (1 예약 O 현재 비어있음) (2. 예약X 누가 앉아있음.) (3. 예약O , 앉아있음)
void setup(void){

  Serial.begin(115200);
  delay(1000);
  WiFi.disconnect();

  Serial.print("Connecting to ");

  Serial.println(ssid);
  
  WiFi.config(ip, gateway, subnet); //와이파이 설정
  WiFi.begin(ssid, password);

  Serial.println(WiFi.SSID());

  WiFi.setAutoConnect(true); //자동 접속 설정

  WiFi.setAutoReconnect(true); //자동 재접속 설정 

  WiFi.waitForConnectResult();

  Serial.println(WiFi.localIP());
  

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  } // 연결 완료 까지 대기

  Serial.println("");

  Serial.print("Connected to ");

  Serial.println(WiFi.SSID());

  Serial.print("IP address: ");

  Serial.println(WiFi.localIP()); //와이파이 설정 출력



  if (MDNS.begin("master")) {

    Serial.println("MDNS responder started");

  }
  
  server.on("/", handleRoot); // 기본 경로에 대한 접속 요청이 있을 때 실행할 함수.
  server.on("/state", HTTP_POST, handleState); // /state 경로에 대한 POST 접속 요청이 있을 때 실행할 함수.
  server.on("/seat1On", [](){ //아래서부터는 웹페이지에서 버튼을 눌러 링크로 연결됬을때 링크 주소에 맞게 실행할 함수들. Seat1이 예약된 경우. Seat1On이다. 
    SendReq(0,true);
    server.sendHeader("Location", "/",true);   //Redirect to our html web page  
    server.send(302, "text/plane","");
  });
  server.on("/seat1Off", [](){
    SendReq(0,false);
    server.sendHeader("Location", "/",true);   //Redirect to our html web page  
    server.send(302, "text/plane","");
  });
  server.on("/seat2On", [](){
    SendReq(1,true);
    server.sendHeader("Location", "/",true);   //Redirect to our html web page  
    server.send(302, "text/plane","");
  });
  server.on("/seat2Off", [](){
    SendReq(1,false);
    server.sendHeader("Location", "/",true);   //Redirect to our html web page  
    server.send(302, "text/plane","");
  });
  server.on("/seat3On", [](){
    SendReq(2,true);
    server.sendHeader("Location", "/",true);   //Redirect to our html web page  
    server.send(302, "text/plane","");
  });
  server.on("/seat3Off", [](){
    SendReq(2,false);
    server.sendHeader("Location", "/",true);   //Redirect to our html web page  
    server.send(302, "text/plane","");
  });
  server.on("/seat4On", [](){
    SendReq(3,true);
    server.sendHeader("Location", "/",true);   //Redirect to our html web page  
    server.send(302, "text/plane","");
  });
  server.on("/seat4Off", [](){
    SendReq(3,false);
    server.sendHeader("Location", "/",true);   //Redirect to our html web page  
    server.send(302, "text/plane","");
  });
  server.begin();
  Serial.println("HTTP server started");

}

void handleRoot() { //html변수에 웹페이지 코드를 추가하는 방식인데, seat배열의 값에 따라 버튼의 색깔을 변경하는 코드가 switch 문이다. 
  String html = "<html><head><title>Black Bordered Div</title><style>.black-bordered-div {border: 2px solid black;display: flex;justify-content: center;align-items: center;text-align: center;width: 100%;;height: 200px; margin: 30 0; }";
  html += ".btn {padding: 10px 20px;margin: 10px; font-size: 5vw;}";
  html += "h2  {font-size: 6vw;}";
  html += "</style></head><body>";
  html += "<h2>Seat Reservation System</h2>";
  html += "<div class=\"black-bordered-div\">";
  html += "<h2>Seat 1</h2>";
  html += "<button ";
  switch (seats[0]) {
    case 0 : 
      html += "style= \"background-color:orange\"";
      break;
    case 1 : 
      html += "style= \"background-color:blue\"";
      break;
    case 2 : 
      html += "style= \"background-color:red\"";
      break;
    case 3 : 
      html += "style= \"background-color:green\"";
      break;
  }
  html += "class=\"btn\" id='seatOn1' onclick='seat1On()'>Reservation</button>";
  html += "<button class=\"btn\" id='seatOff1' onclick='seat1Off()'>Cancel</button>";
  html += "</div>";

  html += "<div class=\"black-bordered-div\">";
  html += "<h2>Seat 2</h2>";
  html += "<button ";
  switch (seats[1]) {
    case 0 : 
      html += "style= \"background-color:orange\"";
      break;
    case 1 : 
      html += "style= \"background-color:blue\"";
      break;
    case 2 : 
      html += "style= \"background-color:red\"";
      break;
    case 3 : 
      html += "style= \"background-color:green\"";
      break;
  }
  html += "class=\"btn\" id='seatOn2' onclick='seat2On()'>Reservation</button>";
  html += "<button class=\"btn\" id='seatOff2' onclick='seat2Off()'>Cancel</button>";
  html += "</div>";

  html += "<div class=\"black-bordered-div\">";
  html += "<h2>Seat 3</h2>";
  html += "<button ";
  switch (seats[2]) {
    case 0 : 
      html += "style= \"background-color:orange\"";
      break;
    case 1 : 
      html += "style= \"background-color:blue\"";
      break;
    case 2 : 
      html += "style= \"background-color:red\"";
      break;
    case 3 : 
      html += "style= \"background-color:green\"";
      break;
  }
  html += "class=\"btn\" id='seatOn3' onclick='seat3On()'>Reservation</button>";
  html += "<button class=\"btn\" id='seatOff3' onclick='seat3Off()'>Cancel</button>";
  html += "</div>";

  html += "<div class=\"black-bordered-div\">";
  html += "<h2>Seat 4</h2>";
  html += "<button ";
  switch (seats[3]) {
    case 0 : 
      html += "style= \"background-color:orange\"";
      break;
    case 1 : 
      html += "style= \"background-color:blue\"";
      break;
    case 2 : 
      html += "style= \"background-color:red\"";
      break;
    case 3 : 
      html += "style= \"background-color:green\"";
      break;
  }
  html += "class=\"btn\" id='seatOn4' onclick='seat4On()'>Reservation</button>";
  html += "<button class=\"btn\" id='seatOff4' onclick='seat4Off()'>Cancel</button>";
  html += "</div>";

  html += "<script>";
  html += "function seat1On() {";
  html += "  var button = document.getElementById('seatOn1');";
  html += "  fetch('/seat1On');"; 
  html += "}";
  html += "function seat1Off() {";
  html += "  var button = document.getElementById('seatOff1');";
  html += "  fetch('/seat1Off');";
  html += "}";
  html += "function seat2On() {";
  html += "  var button = document.getElementById('seatOn2');";
  html += "  fetch('/seat2On');"; 
  html += "}";
  html += "function seat2Off() {";
  html += "  var button = document.getElementById('seatOff2');";
  html += "  fetch('/seat2Off');";
  html += "}";
  html += "function seat3On() {";
  html += "  var button = document.getElementById('seatOn3');";
  html += "  fetch('/seat3On');"; 
  html += "}";
  html += "function seat3Off() {";
  html += "  var button = document.getElementById('seatOff3');";
  html += "  fetch('/seat3Off');";
  html += "}";
  html += "function seat4On() {";
  html += "  var button = document.getElementById('seatOn4');";
  html += "  fetch('/seat4On');"; 
  html += "}";
  html += "function seat4Off() {";
  html += "  var button = document.getElementById('seatOff4');";
  html += "  fetch('/seat4Off');";
  html += "}";
  html += "</script>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleState() { 
  //state 주소로 POST요청이 왔을 때에 POST 데이터를 찾아 기기번호와 상태 정보를 불러오고, 이를 seat 배열에 저장한다. 
  if (server.hasArg("DevNum")) {
    String DevNum = server.arg("DevNum");
    String State = server.arg("State");
    seats[DevNum.toInt()-1] = State.toInt();
    server.send(200, "text/plain", "R");
  } 
}

void SendReq(int num, bool on) {
  //웹페이지에서 버튼을 눌러서 슬레이브에 상태 변경 요청을 보내는 함수. num번째 기기에 on상태의 신호를 보낸다. 
    if (WiFi.status() == WL_CONNECTED) {    
    WiFiClient client;
    HTTPClient http; 
    String target;
    if(on) {
      target = "http://"+String(address[num])+"/On";
    }
    else {
      target = "http://"+String(address[num])+"/Off";
    }
    Serial.println("SENT:"+target);
    http.begin(client,target);  // 마스터 서버의 IP 
    int httpCode = http.GET();

    if (httpCode > 0) { 
      String payload = http.getString();   
      Serial.println(payload);
    }
    else {
      Serial.println("Fail");
    }
    http.end(); 
    }
}

void loop(void){
  server.handleClient();//클라이언트 접속을 관리합니다.

}

