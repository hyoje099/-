#include <LiquidCrystal_I2C.h>
#include <DHT11.h>
#include<DHT.h>
#define pinDHT 11
#define DHTTYPE DHT11
DHT dht (pinDHT,DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2);
int count=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("220821");
  lcd.setCursor(0,1);
  delay(2000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  int h=dht.readHumidity();
  int t=dht.readTemperature();

  Serial.print("Humidity:");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature:");
  Serial.print(t);
  Serial.print(" C");
  Serial.println(count);
  lcd.setCursor(0,0);
  lcd.print("Tem ");
  lcd.print(t);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print(h);
  lcd.print("");
  lcd.setCursor(12,1);
  lcd.print(count);
  delay(1);
  count+=1;
  if(count<9999){
    count=0;
    lcd.clear();
  }
  
}
