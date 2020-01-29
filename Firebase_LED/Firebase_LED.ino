
#include <WiFi.h>                                                 
#include <IOXhop_FirebaseESP32.h>
// Set these to run example.

#define FIREBASE_HOST "esp32-b44ad.firebaseio.com"
#define FIREBASE_AUTH "rH6oEyu3xfLMJun2L6MYG8EQ6XI2mbwWA3UGn3jh"
#define WIFI_SSID "Honor 9N"
#define WIFI_PASSWORD "lokesh13790"
#define LED 2

void setup() {
pinMode(LED,OUTPUT);

digitalWrite(LED,0);

Serial.begin(9600);

WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

Serial.print("connecting");

while (WiFi.status() != WL_CONNECTED) {

Serial.print(".");

delay(500);

}

Serial.println();

Serial.print("connected: ");

Serial.println(WiFi.localIP());

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

Firebase.setInt("LEDStatus",0);

}

void loop() {
String light =Firebase.getString("/Esp32/LEDStatus:");
Serial.println(light);
if(light == "\\\"1\\\"")

{
Serial.println("LEDStatus");
digitalWrite(LED,HIGH);

}

else

{

digitalWrite(LED,LOW);

}

if (Firebase.failed()) {

Serial.print("setting /number failed:");

Serial.println(Firebase.error());

return;
}

}
