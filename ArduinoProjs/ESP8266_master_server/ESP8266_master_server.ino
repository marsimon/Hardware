#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "DimiFi 2G1";
const char* password = "newdimigo";

IPAddress ip(172, 17, 3, 245);
IPAddress gateway(172, 17, 0,1);
IPAddress subnet(255, 255, 252, 0);

ESP8266WebServer server(80);

void handleRoot() {
  if(door==HIGH){
    server.send(200, "text/plain", "1");
  }
  else {
    server.send(200, "text/plain", "0");
  }
}

void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void){
  pinMode(sensor, INPUT);
  Serial.begin(115200);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }
 
  server.on("/", handleRoot);

  server.on("/inline", [](){  
    server.send(200, "text/plain", "this works as well");
  }); 

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  delay(10);
  server.handleClient();
}
