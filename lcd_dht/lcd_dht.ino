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
  char maker[12]={"makerishyoje"};
  for(int i=0;i<12;i++){
    lcd.setCursor(i,0);
    lcd.print(maker[i]);
  }
  lcd.setCursor(0,1);
  delay(2000);
  lcd.clear();
}

void loop() {
  delay(2000);
  int h=dht.readHumidity();
  int h1=h/10;
  int h2=h%10;
  int t=dht.readTemperature();
  int t1=t/10;
  int t2=t%10;
  lcd.setCursor(0,0);
  lcd.print("T");
  lcd.print("e");
  lcd.print("m");
  lcd.print(t1);
  lcd.print(t2);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("H");
  lcd.print("u");
  lcd.print("m");
  lcd.print(h1);
  lcd.print(h2);
  /*
  // put your main code here, to run repeatedly:
  

  Serial.print("Hum:");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature:");
  Serial.print(t);
  Serial.print(" C");
  Serial.println(count);
  
  int x=0,y=0;
  char printing[]
  lcd.print("Tem ");
  lcd.print(t);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print(h);
  lcd.print("");
  lcd.setCursor(12,1);
  delay(1);
  count+=1;
  if(count<9999){
    count=0;
    lcd.clear();
  }*/
  
}
