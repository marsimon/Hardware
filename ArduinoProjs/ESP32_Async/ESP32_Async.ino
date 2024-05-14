#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FirebaseClient.h>
#include <WiFiClientSecure.h>


const unsigned long EVENT_INTERVAL_MS = 10000; //페이지 업데이트 주기

const char *ssid = "TastyWifi"; // 와이파이 SSID & Password
const char *password = "mars1234";


#define API_KEY "AIzaSyA3N0pctFrutd3FsAOuqosPrSoMkVCQlhs"

const char * USER_EMAIL = "k.suzie.97@gmail.com";
const char * USER_PASSWORD = "111111";
#define DATABASE_URL "https://stockcontrol-1599f-default-rtdb.asia-southeast1.firebasedatabase.app/"

void printError(int code, const String &msg);

void asyncCB(AsyncResult &aResult);

void checkSensorString(String sensorString);

void InitFirebase();

DefaultNetwork network; // initilize with boolean parameter to enable/disable network reconnection

FirebaseApp app;

WiFiClientSecure ssl_client;


AsyncClientClass aClient(ssl_client, getNetwork(network));

RealtimeDatabase Database;

AsyncWebServer server(80);
AsyncEventSource events("/events");

unsigned long lastTime = 0;  
unsigned long timerDelay = 10000;

string dir; 
const char *sendData;

String sensorData;
bool sensorValue[16];

uint32_t prev_ms;

bool isLogin;

string table_html1 PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>4x4 테이블</title>
<style>
    table {
        width: 50%;
        border-collapse: collapse;
        margin: 20px auto;
        font-family: 'Arial', sans-serif;
    }
    th, td {
        padding: 40px;
        text-align: center;
        border: 4px solid #ccc;
    }
    #tT, #tT th, #tT td {
    	padding: 5px;
      border: 1px solid transparent; 
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
<table id="tT">
    <tr>
        <td id="c1"></td>
        <td id="c2"></td>
        <td id="c3"></td>
        <td id="c4"></td>
    </tr>
</table>
<div>ADC = <span id="ad_val"></span></div><p></p>
<h3 id="exp">EXP : </h3>
<form id="dateForm">
    <input type="date" id="dateInput" name="date">
    <input type="submit" value="유통기한 설정">
</form>

<script>
if (!!window.EventSource) {
        var source = new EventSource('/events');
        source.addEventListener('open', function(e) {
         console.log("Events Connected");
        }, false);

        source.addEventListener('update', function(e) {
            var ad_value = e.data;
            document.getElementById("ad_val").innerHTML = ad_value;
            
         console.log(ad_value);
           }, false);
}

document.getElementById("dateForm").addEventListener("submit", function(event) {
        event.preventDefault(); // Prevent the form from submitting normally

        var date = document.getElementById("dateInput").value;

        var formData = new FormData();
        formData.append("date", date);
        
        var url = window.location.protocol + "//" + window.location.host + "/login/date"
        fetch(url, {
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
)rawliteral";

string table_html2 PROGMEM = R"rawliteral(
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

        var url = window.location.protocol + "//" + window.location.host + "/login"

        fetch(url, {
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

String processor(const String& var){
  return var;
}

void handle_root(AsyncWebServerRequest *request) {
  request->send_P(200, "text/html", index_html, processor);
}

void handle_login(AsyncWebServerRequest *request)
{
  string html;
  Serial.println("Login request arrived");
  if(request->hasParam("email", true)) {
    AsyncWebParameter* p = request->getParam("email", true);
    USER_EMAIL = p->value().c_str();
    p = request->getParam("password", true);
    USER_PASSWORD = p->value().c_str();

    InitFirebase();
    Serial.print("Get data... ");
    sensorData = Database.get<String>(aClient, (dir+"/1").c_str());
    if (aClient.lastError().code() == 0) {
      
      Serial.println(sensorData);
      checkSensorString(sensorData);
    }
    else
      printError(aClient.lastError().code(), aClient.lastError().message());
    
    int arr[4]={0};
    for(int i=0;i<16;i++) {
      if(sensorValue[i]) {
        arr[i%4]++;
      }
    }
    html += "document.getElementById('c1').textContent = 'Stock A : ";
    html +=  String(arr[0]).c_str();
    html += "';";
    html += "document.getElementById('c2').textContent = 'Stock B : ";
    html +=  String(arr[1]).c_str();
    html += "';";
    html += "document.getElementById('c3').textContent = 'Stock C : ";
    html +=  String(arr[2]).c_str();
    html += "';";
    html += "document.getElementById('c4').textContent = 'Stock D : ";
    html +=  String(arr[3]).c_str();
    html += "';";
    
    Serial.print("Get date... ");
    String v3 = Database.get<String>(aClient, (dir+"/2").c_str());
    if (aClient.lastError().code() == 0) {
      Serial.println(v3);
      html += "document.getElementById('exp').textContent = 'Expiration date : ";
      html += v3.c_str();
      html += "';";

    }
    else {
      html += "document.getElementById('exp').textContent = 'Expiration date : N/A";
      printError(aClient.lastError().code(), aClient.lastError().message());
    }
  }
  //HTML 구성
  for(int i=1;i<5;i++) {
    for(int j=1;j<5;j++) {
      html += "document.getElementById('cell";
      html += String(i).c_str();
      html += String(j).c_str();
      html += "').style.backgroundColor =";
      if(sensorValue[(i-1)*4 + j-1] ) {
        html += "'white';";
      }
      else {
        html += "'red';\n";
      }
    }
  }
  request->send_P(200, "text/html", (table_html1+html+table_html2).c_str() , processor);
}

void handle_date(AsyncWebServerRequest *request)
{
  if(request->hasParam("date", true)) {
    AsyncWebParameter* p = request->getParam("date", true);
    Serial.println(p->value().c_str());
    InitFirebase();
    
    bool status = Database.set<String>(aClient, (dir+"/2").c_str(),p->value().c_str());
    if (status)
        Serial.println("Set string is ok");
    else
        printError(aClient.lastError().code(), aClient.lastError().message());
  }
}

void InitWebServer() 
{
  server.addHandler(&events);
  server.on("/", handle_root);
  server.on("/login", handle_login);
  server.on("/login/date", handle_date);
  server.begin();
}


void InitFirebase() {
  Serial.println(USER_EMAIL);
  ssl_client.setInsecure();
  app.setCallback(asyncCB);
  UserAuth user_auth(API_KEY, USER_EMAIL, USER_PASSWORD);
  initializeApp(aClient, app, getAuth(user_auth));

  // Waits for app to be authenticated.
  // For asynchronous operation, this blocking wait can be ignored by calling app.loop() in loop().
  unsigned long ms = millis();
  while (app.isInitialized() && !app.ready() && millis() - ms < 120 * 1000);
  app.getApp<RealtimeDatabase>(Database);
  Database.url(DATABASE_URL);
  dir = ("/"+app.getUid()).c_str();
}

void setup() {
	Serial.begin(115200);
	Serial.println("ESP32 Simple web Start");
	Serial.println(ssid);
  
  prev_ms = millis();
  /*
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }*/
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
}

void ProcessUpdate()
{
  if (millis() > prev_ms + EVENT_INTERVAL_MS)
  {
    Serial.println("update Event Sent");
    events.send(sensorData.c_str(),"update", millis());
    prev_ms = millis();
  }
}

void loop() {
  ProcessUpdate();
  app.loop();

}

void checkSensorString(String sensorString) {
  for (int i = 0; i < sensorString.length(); ++i) {
    char currentChar = sensorString.charAt(i);
    if(currentChar=='0') {
      sensorValue[i] = false;
    }
    else {
      sensorValue[i] = true;
    }
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
