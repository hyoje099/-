#include <LiquidCrystal_I2C.h>     //LiquidCrystal 라이브러리 추가 
LiquidCrystal_I2C lcd(0x27, 16, 2);  //lcd 객체 선언
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(); //LCD 사용 시작
  pinMode(7,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int readValue = digitalRead(7);
  Serial.println(readValue);
  if(readValue ==HIGH){
    lcd.setCursor(5, 0);    // 커서를 5, 0에 가져다 놓아라. (열, 행)
    lcd.print("Hi ^^");     // 5, 0에 Hi ^^를 출력해라.
    delay(1000);            // 1초 대기
    lcd.setCursor(3, 1);    // 커서를 3, 1로 가져다 놓아라. (열, 행)
    lcd.print("010-1111-1111"); // 010-1111-1111을 입력해라.
    delay(1000);            // 1초 대기 
    lcd.clear();            // 글자를 모두 지워라.
    delay(1000);            // 1초 대기
  }
  else{
    digitalWrite(8,LOW);
  }
}
