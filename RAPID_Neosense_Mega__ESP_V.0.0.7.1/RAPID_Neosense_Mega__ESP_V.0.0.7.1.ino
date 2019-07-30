#include "config.h"
void setup() {
  SerialMega.begin(9600);
  Serial.begin(115200);
  pinMode(pinLED,OUTPUT);
  pinMode(pinReset,OUTPUT);
  digitalWrite(pinReset,HIGH);
}

void loop() {
  digitalWrite(pinLED,HIGH);
  SerialMega.flush();
  parsingData(getDataFromMega());
  SerialFlash("SO2   : "); Serial.print(SO2ppb); SerialFlashln(" ppb");
  SerialFlash("NO2   : "); Serial.print(NO2ppb); SerialFlashln(" ppb");
  SerialFlash("CO    : "); Serial.print(COppb);  SerialFlashln(" ppb");
  SerialFlash("O3    : "); Serial.print(O3ppb);  SerialFlashln(" ppb");
  SerialFlash("PM1   : "); Serial.print(PM1);    SerialFlashln(" ug/m3");
  SerialFlash("PM2.5 : "); Serial.print(PM25);   SerialFlashln(" ug/m3");
  SerialFlash("PM10  : "); Serial.print(PM10);   SerialFlashln(" ug/m3");
  SerialFlash("Temperature : "); Serial.print(temperature);   SerialFlashln(" 'C");
  SerialFlash("Humidity    : "); Serial.print(hum);   SerialFlashln(" %");
  SerialFlash("Pressure    : "); Serial.print(pressure);   SerialFlashln(" Pa");
  if (jumlahKoma >= 8){
    SerialMega.flush();
    digitalWrite(pinLED,HIGH);
    for(int z = 0;z<10;z++){
      digitalWrite(pinLED,!(digitalRead(pinLED))); 
      delay(100); 
    }
    digitalWrite(pinLED,LOW);
    SerialFlashln("Data Valid, Continue Upload");
    UploadToDashboard();
    delay(5000);
    SerialMega.flush();
  } else {
    SerialMega.flush();
    SerialFlashln("Data Invalid, Halt Upload, Wait next Data");
  }
  if(cekTimeout){
    resetArduinoMega();
  }
}
