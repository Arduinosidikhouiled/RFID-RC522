#include <SPI.h>
#include <RFID.h>
RFID rfid(10, 9);
byte SK[5] = {202,32,38,180,120};
//202,32,38,180,120 My card
boolean card;
int BUZZER= 3;
int ledR= 4;
int ledG= 5;

void setup(){
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
    
pinMode(BUZZER,OUTPUT);
pinMode(ledR,OUTPUT);
pinMode(ledG,OUTPUT);}

void loop(){
  if (rfid.isCard()){
    if (rfid.readCardSerial()){
      Serial.print("Found ID: ");
      Serial.print(rfid.serNum[0]);
      Serial.print(",");
      Serial.print(rfid.serNum[1]);
      Serial.print(",");
      Serial.print(rfid.serNum[2]);
      Serial.print(",");
      Serial.print(rfid.serNum[3]);
      Serial.print(",");
      Serial.println(rfid.serNum[4]);}
    for (int i = 1; i < 5; i++){
      if 
       ( rfid.serNum[0] == SK[0] 
      && rfid.serNum[1] == SK[1] 
      && rfid.serNum[2] == SK[2] 
      && rfid.serNum[3] == SK[3] 
      && rfid.serNum[4] == SK[4] )
      {  
       card = true;
      }
      else { card = false; }}
    
    if (card == true){
      Serial.println("Correct Card");
       digitalWrite(ledG,HIGH);
       delay(2000);
       digitalWrite(ledG,LOW);}
    else{
      Serial.println("Wrong Card");
      digitalWrite(ledR,HIGH);
      digitalWrite(BUZZER,HIGH);
      delay(2000);
      digitalWrite(ledR,LOW);
      digitalWrite(BUZZER,LOW);}
    rfid.halt();}}
