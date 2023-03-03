//Libreries
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Information about this ESP8266
#define ID "eyJuYW1lIjoiTU9EMDAwLUVTUDAwMCIsImlhdCI6MX0"
#define ESP_NAME "MOD000-ESP000"

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

boolean ValuesOfBits[8] = {true, false, true, false, true, false, true, false}; //Este arreglo debe ser guardado en memoria, Es el estado de los datos.


void esp_presets(){ //Funcion que configura el nodo de el ESP.
  Firebase.set("MOD000-ESP000/ID", ID); //Establece su ID
  
  for(int i = 0; i <= 7; i++){ // Loop que hace que se creen todos los bits y se agregen su valor guardado en la EPROM
    Firebase.set(String(ESP_NAME) + "/B" + String(i), ValuesOfBits[i]);
    }
    
    for(int i = 0; i < 7; i++){ //Imprime por consola el estado de los BITS
      Serial.println(String(ValuesOfBits[i]));
    }
    
   if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
   }
}

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


  //Esta era una logica para hacer que no se repitieran los datos, pero la reemplace
  //if(){
    //Serial.println("ESP: " + String(ESP_NAME) + " already exist...");
    //Serial.println(Firebase.getBool(ESP_NAME));
    //} else {
        esp_presets();
        //Serial.println(Firebase.getBool(ESP_NAME));
      //}
}
int n = 0;

void loop() {
  //if(Firebase.getBool("led/")){
     //digitalWrite(D4, LOW);
    //} else {
      //digitalWrite(D4, HIGH);
      //}
      
  
  // update value
  //Firebase.setFloat("number", 43.0);
  // handle error
  //if (Firebase.failed()) {
      //Serial.print("setting /number failed:");
      //Serial.println(Firebase.error());  
      //return;
  //}
  //delay(1000);

  // get value 
  //Serial.print("number: ");
  //Serial.println(Firebase.getFloat("number"));
  //delay(1000);

  // remove value
  //Firebase.remove("number");
  //delay(1000);

  // set string value
  //Firebase.setString("message", "hello world");
  // handle error
  //if (Firebase.failed()) {
      //Serial.print("setting /message failed:");
      //Serial.println(Firebase.error());  
      //return;
  //}
  //delay(1000);
  
  // set bool value
  //Firebase.setBool("truth", false);
  // handle error
  //if (Firebase.failed()) {
      //Serial.print("setting /truth failed:");
      //Serial.println(Firebase.error());  
      //return;
  //}
  //delay(1000);

  
  //Serial.print("pushed: /logs/");
  //Serial.println(name);
  
  //delay(1000);
  //digitalWrite(D4,LOW);
  //delay(1000);
  //digitalWrite(D4,HIGH);
  //delay(1000);
}
