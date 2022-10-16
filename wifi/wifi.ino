#include <ESP8266HTTPClient.h>

#include<ESP8266WiFi.h>

char*wifi_name="SK_WiFi4FED";
char*password="1402033324";

void serup(){
    Serial.begin(115200);
    WiFi.begin(wifi_name,password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print("Connecting...");
    }
    
}
void loop(){
    if(WiFi.status() == WL_CONNECTED){
        HTTPClient http;
        String getRequestURL = "http://127.0.0.1:8000/";
        String name ="wonjun";
        String age = "50";

        getRequestURL +="/name/";
        getRequestURL +=name;
        getRequestURL +="/age/";
        getRequestURL += age;

        http.begin(getRequestURL);

        int httpCode = http. GET();
        if(httpCode>0){
            String payload =http.getString();
            Serial.println(payload);
        }
        http.end();
    }
    delay(3000);
}
