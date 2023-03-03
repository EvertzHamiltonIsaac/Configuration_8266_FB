//Libreries
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Information about this ESP8266
#define IP_ESP "0000:DB0:0000::"
#define ID "eyJuYW1lIjoiTU9EMDAwLUVTUDAwMCIsImlhdCI6MX0"
#define PATH_ESP "0000:DB0:0000::/ESP_NAME"
#define ESP_NAME "MOD000-ESP000"

// Set these to run example.
#define FIREBASE_HOST "final-project-web-v0-default-rtdb.firebaseio.com" //Host of database
#define FIREBASE_AUTH "twTgN3QF2zoEPxBhPF4rp06uZiSx1zFu9jDPNPnp" //code of authentication
#define WIFI_SSID "Inter-Flash"
#define WIFI_PASSWORD "A123456789"

//ESP8266 physical outputs
#define BIT_0 16 //D0 of ESP8266
#define BIT_1 5  //D1 of ESP8266
#define BIT_2 4  //D2 of ESP8266
#define BIT_3 0  //D3 of ESP8266

#define BIT_VOLT_0 2  //D4 of ESP8266
#define BIT_VOLT_1 14 //D5 of ESP8266
#define BIT_VOLT_2 12 //D6 of ESP8266
#define BIT_VOLT_3 13 //D7 of ESP8266


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
  
  pinMode(BIT_0, OUTPUT);
  pinMode(BIT_1, OUTPUT);
  pinMode(BIT_2, OUTPUT);
  pinMode(BIT_3, OUTPUT);
  pinMode(BIT_VOLT_0, OUTPUT);
  pinMode(BIT_VOLT_1, OUTPUT);
  pinMode(BIT_VOLT_2, OUTPUT);
  pinMode(BIT_VOLT_3, OUTPUT);
  
  detectYourself();
}

void detectYourself(){
  if(Firebase.getString(PATH_ESP) == ESP_NAME){
      Serial.println("ESP Local Information");
      Serial.println("IP: " + String(IP_ESP));
      Serial.println("PATH IN DATABASE " + String(PATH_ESP));
      Serial.println("ESP NAME: " + String(ESP_NAME));
    }else{
      Serial.print("The ESP are not vinculated with the database.");
    }
  }
  
void loop() {

//--------------------------------------------------------------------B0--------------------------------------------------------------------
  boolean state_b0 = Firebase.getBool("0000:DB0:0000::/B0/estado");
   if (Firebase.failed()) {
      Serial.print("Error verificando estado:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1500);
  
  if(state_b0 == true){
    
    String voltaje = Firebase.getString("0000:DB0:0000::/B0/voltaje");
    if (Firebase.failed()) {
      Serial.print("Error verificando voltaje:");
      Serial.println(Firebase.error());  
      return;
    }
    delay(1000);
    
    if(voltaje == "vl"){
        digitalWrite(BIT_0,HIGH);
        digitalWrite(BIT_VOLT_0,LOW);
        Serial.println("B0 ON - 15V");
      } else if (voltaje == "vh"){
         digitalWrite(BIT_0,HIGH);
         digitalWrite(BIT_VOLT_0,HIGH);
         Serial.println("B0 ON - 30V");
        }
   } else if (!state_b0){
         digitalWrite(BIT_0,LOW);
         digitalWrite(BIT_VOLT_0,LOW);
         Serial.println("B0 OFF 0V");    
     }
   delay(1000);
   
//--------------------------------------------------------------------B1--------------------------------------------------------------------
   boolean state_b1 = Firebase.getBool("0000:DB0:0000::/B1/estado");
   if (Firebase.failed()) {
      Serial.print("Error verificando estado:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1500);
  
  if(state_b1 == true){
    
    String voltaje = Firebase.getString("0000:DB0:0000::/B1/voltaje");
    if (Firebase.failed()) {
      Serial.print("Error verificando voltaje");
      Serial.println(Firebase.error());  
      return;
    }
    delay(1000);
    
    if(voltaje == "vl"){
        digitalWrite(BIT_1,HIGH);
        digitalWrite(BIT_VOLT_1,LOW);
        Serial.println("B1 ON - 15V");
      } else if (voltaje == "vh"){
         digitalWrite(BIT_1,HIGH);
         digitalWrite(BIT_VOLT_1,HIGH);
         Serial.println("B1 ON - 30V");
        }
   } else if (!state_b0){
         digitalWrite(BIT_0,LOW);
         digitalWrite(BIT_VOLT_0,LOW);
         Serial.println("B1 OFF 0V");    
     }
   delay(1000);
//--------------------------------------------------------------------B2--------------------------------------------------------------------
   boolean state_b2 = Firebase.getBool("0000:DB0:0000::/B2/estado");
   if (Firebase.failed()) {
      Serial.print("Error verificando estado:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1500);
  
  if(state_b2 == true){
    
    String voltaje = Firebase.getString("0000:DB0:0000::/B2/voltaje");
    if (Firebase.failed()) {
      Serial.print("Error verificando voltaje");
      Serial.println(Firebase.error());  
      return;
    }
    delay(1000);
    
    if(voltaje == "vl"){
        digitalWrite(BIT_2,HIGH);
        digitalWrite(BIT_VOLT_2,LOW);
        Serial.println("B2 ON - 15V");
      } else if (voltaje == "vh"){
         digitalWrite(BIT_2,HIGH);
         digitalWrite(BIT_VOLT_2,HIGH);
         Serial.println("B2 ON - 30V");
        }
   } else if (!state_b2){
         digitalWrite(BIT_2,LOW);
         digitalWrite(BIT_VOLT_2,LOW);
         Serial.println("B2 OFF 0V");    
     }
   delay(1000); 
   //--------------------------------------------------------------------B3--------------------------------------------------------------------
   boolean state_b3 = Firebase.getBool("0000:DB0:0000::/B3/estado");
   if (Firebase.failed()) {
      Serial.print("Error verificando estado:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1500);
  
  if(state_b3 == true){
    
    String voltaje = Firebase.getString("0000:DB0:0000::/B3/voltaje");
    if (Firebase.failed()) {
      Serial.print("Error verificando voltaje");
      Serial.println(Firebase.error());  
      return;
    }
    delay(1000);
    
    if(voltaje == "vl"){
        digitalWrite(BIT_1,HIGH);
        digitalWrite(BIT_VOLT_1,LOW);
        Serial.println("B3 ON - 15V");
      } else if (voltaje == "vh"){
         digitalWrite(BIT_3,HIGH);
         digitalWrite(BIT_VOLT_3,HIGH);
         Serial.println("B3 ON - 30V");
        }
   } else if (!state_b3){
         digitalWrite(BIT_3,LOW);
         digitalWrite(BIT_VOLT_3,LOW);
         Serial.println("B3 OFF 0V");    
     }
   delay(1000);
}
