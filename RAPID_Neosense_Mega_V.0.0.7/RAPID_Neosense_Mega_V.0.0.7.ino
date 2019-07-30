#include "config.h"
void setup() {
  initFunction();
}

void loop() {
  clearCursor();
  pumpOn();
  TFTFlashln("---------------------");
  SerialFlash("Filling Air");
  TFTFlash("Filling Air");
  for(int i = 0 ; i< 10;i++){
    SerialFlash(".");
    TFTFlash(".");
    delay(1000);
  }
  tft.println();
  TFTFlashln("---------------------");
  startSPECSensorSO2();
  startSPECSensorCO();
  startSPECSensorNO2();
  startSPECSensorO3();
  getBME280();
  TFTFlashln("Get PM Data");
  for(int i = 0; i<5 ; i++){
    PM1  = 0;
    PM25 = 0;
    PM10 = 0;
    Winsen_ZH03A(0);
    if ((PM1 == 0) || (PM25 == 0) || (PM10 == 0)){
      SerialFlash("Remeasuring #");Serial.println(i);
      TFTFlash("Remeasuring #");tft.println(i);
      Winsen_ZH03A(0);
    } else {
      break;
    }
  }
  pumpOff();
  clearCursor();
  displayData();
  Serial.println(combineAllText());
  sendToSerial(combineAllText());
  delay(5000);
  clearCursor();
  SerialFlashln("Next Upload :");
  for(int i = 0 ; i< timeUpload ;i++){
    if (i % 60 == 0){
      TFTFlash("Next Upload : ");tft.println(300-i);
    }
    Serial.println(i);
    delay(1000);
  }
}

void Soft_Reset() {
  Serial.println("RESET !");
  asm volatile ("  jmp 0");  
}  

void blinkLED(void){
  digitalWrite(pinLED,!(digitalRead(pinLED)));
}
