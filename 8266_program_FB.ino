#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "final-project-web-v0-default-rtdb.firebaseio.com" //Host of database
#define FIREBASE_AUTH "twTgN3QF2zoEPxBhPF4rp06uZiSx1zFu9jDPNPnp" //code of authentication
#define WIFI_SSID "Inter-Flash"
#define WIFI_PASSWORD "A123456789"

//ESP8266 physical outputs
#define D0 16 //D0 of ESP8266
#define D1 5  //D1 of ESP8266
#define D2 4  //D2 of ESP8266
#define D3 0  //D3 of ESP8266
#define D4 2  //D4 of ESP8266
#define D5 14 //D5 of ESP8266
#define D6 12 //D6 of ESP8266
#define D7 13 //D7 of ESP8266

// LED tiene logica negativa 

void setup() {
   Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST);

  pinMode(D4, OUTPUT);
}

int n = 0;

void loop() {
  // put your main code here, to run repeatedly:
  // set value
  Firebase.setFloat("number", 42.0);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // update value
  Firebase.setFloat("number", 43.0);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // get value 
  Serial.print("number: ");
  Serial.println(Firebase.getFloat("number"));
  delay(1000);

  // remove value
  Firebase.remove("number");
  delay(1000);

  // set string value
  Firebase.setString("message", "hello world");
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // set bool value
  Firebase.setBool("truth", false);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /truth failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // append a new value to /logs
  String name = Firebase.pushInt("logs", n++);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /logs/");
  Serial.println(name);
  
  //delay(1000);
  //digitalWrite(D4,LOW);
  //delay(1000);
  //digitalWrite(D4,HIGH);
  //delay(1000);
}
