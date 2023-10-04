#include <SimpleDHT.h>
int pinDHT11 = 4;


SimpleDHT11 dht11;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(11, OUTPUT); //vang
pinMode(12, OUTPUT); //xanh
pinMode(13, OUTPUT); //dor

}

void loop() {
  // put your main code here, to run repeatedly:

  byte x = 0;
  byte y = 0;
  byte nhietdo;
  byte doam;
  int err = SimpleDHTErrSuccess;
  Serial.println("========================");
  if((err = dht11.read(pinDHT11, &x, &y, NULL)) != SimpleDHTErrSuccess){
    Serial.print("Read DHT11 failed, err=");
    Serial.println(err);
    delay(1000);
    return;
  }
  Serial.print("Humidity =");
  Serial.print((int)y);
  Serial.print("%, ");
  Serial.print("Temperature");
  Serial.print((int)x);
  Serial.print("oC ");
  delay(3000);
  if(x > 25){
   
   nhietdo = 1;
   
  }
  else if(x < 23){
    
    nhietdo = 2;  
  }
  else{
  
    nhietdo = 3;  
  }

  if(y > 0.5){
    doam = 1;
  }
  else{
   doam = 2;  
  }
  
  
  switch (nhietdo) {
  case 1:
    // statements
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    break;
  case 2:
    digitalWrite(11,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    // statements
    break;
  case 3:
    digitalWrite(12,HIGH);
    delay(500);
    digitalWrite(11,LOW);
    digitalWrite(13,LOW);
    break;
  default:
    // statements
    Serial.println(err);
    break;
}

  switch (doam) {
  case 1:
    // statements
    digitalWrite(13,HIGH);
     digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
    digitalWrite(13,HIGH);
     digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    delay(500);
    digitalWrite(13,LOW);
    
    
    break;
  case 2:
    digitalWrite(12,HIGH);
     digitalWrite(11,LOW);
    digitalWrite(13,LOW);
    delay(500);
    digitalWrite(12,LOW);
    delay(500);
    digitalWrite(12,HIGH);
     digitalWrite(11,LOW);
    digitalWrite(13,LOW);
    delay(500);
    digitalWrite(12,LOW);
    // statements
    break;
  
  default:
    // statements
    Serial.println(err);
    break;
}

  Serial.print("Humidity =");
  Serial.print((int)y);
  Serial.print("%, ");
  Serial.print("Temperature");
  Serial.print((int)x);
  Serial.print("oC ");


  delay(3000);

}
