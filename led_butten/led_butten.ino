void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(7,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int readValue = digitalRead(7);
  Serial.println(readValue);
  if(readValue ==HIGH){
    digitalWrite(8,HIGH);
    delay(1000);
  }
  else{
    digitalWrite(8,LOW);
  }
}
