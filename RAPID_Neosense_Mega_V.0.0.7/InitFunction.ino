void initFunction(){
  timerInterrupt();
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(0);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0,0);
  TFTFlashln("---------------------");
  tft.println("Sensync - RAPID");
  tft.println("Sensor Reader");
  TFTFlashln("---------------------");
  
  pinMode(pinInterrupt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinInterrupt), Soft_Reset, FALLING);
  
  Serial.begin(115200);
  sensorSO2.begin(9600);
  sensorCO.begin(9600);
  sensorNO2.begin(9600);
  sensorO3.begin(9600);
  SerialESP.begin(9600);
  pinMode(pinPump,OUTPUT);
  SerialFlash("Booting up SPEC Sensor");
  TFTFlashln("Boot up SPEC Sensor");
  for (int i = 0 ; i < 5 ; i++){
    SerialFlash(".");
    delay(1000);
  }
  Serial.println();
  
  Winsen_Port.begin(9600);
  
  TFTFlashln("Check BME280 ");
  Wire.begin();
  bme280.setI2CAddress(0x76); 
  if(bme280.beginI2C() == false){
    Serial.println("BME280 connect failed");
    TFTFlashln("BME280 connect failed");
  } else  {
    Serial.println(F("OK"));
    TFTFlashln("OK");
  }
  delay(2000);
  tft.fillScreen(ST77XX_BLACK);
}
