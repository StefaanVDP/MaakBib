#include <SoftwareSerial.h>

SoftwareSerial hc06(4,5);


void setup(){
  //Initialiseer de Seriële Monitor
  Serial.begin(9600);

  Serial.println("Geef een AT Commando:");
  //Initialiseer de Bluetooth connectie
  hc06.begin(9600);
}

void loop(){
  //schrijf van HC06 naar de Seriële Monitor
  if (hc06.available()){
    Serial.write(hc06.read());
  }
  
  //schrijf van Seriële Monitor naar HC06
  if (Serial.available()){
    hc06.write(Serial.read());
  }  
}
