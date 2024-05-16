
#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

IPAddress local_IP(192, 168, 207, 129); //  서버 고정 IP 주소
IPAddress gateway(192, 168, 207, 129);
IPAddress subnet(255, 255, 255, 0);

#include <FirebaseClient.h>

#define API_KEY "AIzaSyA3N0pctFrutd3FsAOuqosPrSoMkVCQlhs"

#define USER_EMAIL "simon5678@naver.com"
#define USER_PASSWORD "mars-1234"
#define DATABASE_URL "https://stockcontrol-1599f-default-rtdb.asia-southeast1.firebasedatabase.app/"

void printError(int code, const String &msg);

void asyncCB(AsyncResult &aResult);

void checkSensorString(String sensorString);
int readMux(int channel);

DefaultNetwork network; // initilize with boolean parameter to enable/disable network reconnection

FirebaseApp app;

#include <WiFiClientSecure.h>
WiFiClientSecure ssl_client;

using AsyncClient = AsyncClientClass;

AsyncClient aClient(ssl_client, getNetwork(network));

RealtimeDatabase Database;

//MUX 선택을 위한 디지털 핀
const int s0 = 8;
const int s1 = 9;
const int s2 = 10;
const int s3 = 11;

//Mux 입력 아날로그 핀
const int SIG_pin = 0;

bool sensorValues[16];

const char *ssid = "MarsHome"; // 와이파이 SSID & Password
const char *password = "mars-1234";

WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)
void handle_root();

const char table_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>4x4 테이블</title>
<style>
    table {
        border-collapse: collapse;
        width: 50%;
    }
    td {
        border: 1px solid black;
        padding: 10px;
        text-align: center;
    }
</style>
</head>
<body>

<table>
    <tr>
        <td id="cell11"></td>
        <td id="cell12"></td>
        <td id="cell13"></td>
        <td id="cell14"></td>
    </tr>
    <tr>
        <td id="cell21"></td>
        <td id="cell22"></td>
        <td id="cell23"></td>
        <td id="cell24"></td>
    </tr>
    <tr>
        <td id="cell31"></td>
        <td id="cell32"></td>
        <td id="cell33"></td>
        <td id="cell34"></td>
    </tr>
    <tr>
        <td id="cell41"></td>
        <td id="cell42"></td>
        <td id="cell43"></td>
        <td id="cell44"></td>
    </tr>
</table>

<script>
    // 각 셀에 대해 랜덤한 색상을 지정합니다.
    function randomColor() {
        return '#' + Math.floor(Math.random()*16777215).toString(16);
    }

    // 각 셀에 랜덤한 색상을 적용합니다.
    document.getElementById('cell11').style.backgroundColor = randomColor();
    document.getElementById('cell12').style.backgroundColor = randomColor();
    document.getElementById('cell13').style.backgroundColor = randomColor();
    document.getElementById('cell14').style.backgroundColor = randomColor();
    document.getElementById('cell21').style.backgroundColor = randomColor();
    document.getElementById('cell22').style.backgroundColor = randomColor();
    document.getElementById('cell23').style.backgroundColor = randomColor();
    document.getElementById('cell24').style.backgroundColor = randomColor();
    document.getElementById('cell31').style.backgroundColor = randomColor();
    document.getElementById('cell32').style.backgroundColor = randomColor();
    document.getElementById('cell33').style.backgroundColor = randomColor();
    document.getElementById('cell34').style.backgroundColor = randomColor();
    document.getElementById('cell41').style.backgroundColor = randomColor();
    document.getElementById('cell42').style.backgroundColor = randomColor();
    document.getElementById('cell43').style.backgroundColor = randomColor();
    document.getElementById('cell44').style.backgroundColor = randomColor();
</script>

</body>
</html>
)rawliteral";

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Login Form</title>
<style>
    /* Add some basic styling */
    body {
        font-family: Arial, sans-serif;
    }
    .container {
        max-width: 400px;
        margin: 0 auto;
        padding: 20px;
        border: 1px solid #ccc;
        border-radius: 5px;
        background-color: #f9f9f9;
    }
    input[type="text"],
    input[type="password"],
    input[type="submit"] {
        width: 100%;
        padding: 10px;
        margin: 5px 0;
        display: inline-block;
        border: 1px solid #ccc;
        border-radius: 4px;
        box-sizing: border-box;
    }
    input[type="submit"] {
        background-color: #4CAF50;
        color: white;
        cursor: pointer;
    }
    input[type="submit"]:hover {
        background-color: #45a049;
    }
</style>
</head>
<body>
<div class="container">
    <h2>Login</h2>
    <form id="loginForm">
        <label for="email">Email:</label>
        <input type="text" id="email" name="email" required>
        <label for="password">Password:</label>
        <input type="password" id="password" name="password" required>
        <input type="submit" value="Login">
    </form>
</div>

<script>
    document.getElementById("loginForm").addEventListener("submit", function(event) {
        event.preventDefault(); // Prevent the form from submitting normally

        // Get the values from the form
        var email = document.getElementById("email").value;
        var password = document.getElementById("password").value;

        var formData = new FormData();
        formData.append("email", email);
        formData.append("password", password);

        fetch('http://192.168.207.129/login', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded',
            },
            body: new URLSearchParams(formData).toString()
        })
        .then(response => response.text())
        .then(data => {
            // Handle the response from the server
            console.log(data);
            // Reload the page with the received HTML content
            document.open();
            document.write(data);
            document.close();
        })
        .catch(error => {
            console.error('Error:', error);
        });
        
    });
</script>

</body>
</html>
)rawliteral";



//페이지 요청이 들어 오면 처리 하는 함수
void handle_root()
{
  server.send(200, "text/html", index_html);
}

void handle_login()
{
  if (server.hasArg("email")) {
    String email = server.arg("email");
    String password = server.arg("password");
  }
  server.send(200, "text/html", table_html);
}

void InitWebServer() 
{
	//페이지 요청 처리 함수 등록
	server.on("/", handle_root);
  server.on("/login", handle_login);
  server.begin();
}

UserAuth user_auth(API_KEY, USER_EMAIL, USER_PASSWORD);

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
}

void setup() {
	Serial.begin(115200);
	Serial.println("ESP32 Simple web Start");
	Serial.println(ssid);

  /*
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW); 
  */
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }
	//WiFi 접속
	WiFi.begin(ssid, password);

	//접속 완료 하면
	while (WiFi.status() != WL_CONNECTED) {
	delay(1000);
	Serial.print(".");
	}
    
	Serial.print("Wifi IP: ");
	Serial.println(WiFi.localIP());  //Show ESP32 IP on serial

	InitWebServer(); 
	Serial.println("HTTP server started");
	delay(100); 

  InitFirebase();

  Serial.print("Get string... ");
    String v3 = Database.get<String>(aClient, "/test/string");
    if (aClient.lastError().code() == 0) {
      
        Serial.println(v3);
        checkSensorString(v3);
    }
    else
        printError(aClient.lastError().code(), aClient.lastError().message());
}

void loop() {

  server.handleClient();
  app.loop();

  /*for(int i = 0; i < 16; i ++){
    if(readMux(i) > 512) 
      sensorValues[i] = true;
    else sensorValues[i] = false;
    delay(10); 
  }
  String result = "";
  for (int i = 0; i < 16; ++i) {
    result += array[i] ? "1" : "0";
  } 
  */
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

void checkSensorString(String sensorString) {
  for (int i = 0; i < sensorString.length(); ++i) {
    char currentChar = sensorString.charAt(i);
    Serial.println(currentChar);
    // 여기서 각각의 문자열을 처리할 수 있습니다.
  }
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
