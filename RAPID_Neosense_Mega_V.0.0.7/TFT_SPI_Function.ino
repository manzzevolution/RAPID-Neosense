void clearLine(int z){
  tft.fillRect(0, z * 7, tft.width(), 8, ST7735_BLACK);
}
void clearCursor(){
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0,0);
}
void displayData(){
  SerialFlash("SO2   : "); Serial.print(SO2ppb); SerialFlashln(" ppb");
  SerialFlash("NO2   : "); Serial.print(NO2ppb); SerialFlashln(" ppb");
  SerialFlash("CO    : "); Serial.print(COppb);  SerialFlashln(" ppb");
  SerialFlash("O3    : "); Serial.print(O3ppb);  SerialFlashln(" ppb");
  SerialFlash("PM1   : "); Serial.print(PM1);    SerialFlashln(" ug/m3");
  SerialFlash("PM2.5 : "); Serial.print(PM25);   SerialFlashln(" ug/m3");
  SerialFlash("PM10  : "); Serial.print(PM10);   SerialFlashln(" ug/m3");
  SerialFlash("Temp  : "); Serial.print(temperature);   SerialFlashln(" 'C");
  SerialFlash("Hum   : "); Serial.print(hum);   SerialFlashln(" %");
  TFTFlashln("Sample Data");
  TFTFlash("SO2   : "); tft.print(SO2ppb); TFTFlashln(" ppb");
  TFTFlash("NO2   : "); tft.print(NO2ppb); TFTFlashln(" ppb");
  TFTFlash("CO    : "); tft.print(COppb);  TFTFlashln(" ppb");
  TFTFlash("O3    : "); tft.print(O3ppb);  TFTFlashln(" ppb");
  TFTFlash("PM1   : "); tft.print(PM1);    TFTFlashln(" ug/m3");
  TFTFlash("PM2.5 : "); tft.print(PM25);   TFTFlashln(" ug/m3");
  TFTFlash("PM10  : "); tft.print(PM10);   TFTFlashln(" ug/m3");
  TFTFlash("Temp  : "); tft.print(temperature);   TFTFlashln(" 'C");
  TFTFlash("Hum   : "); tft.print(hum);   TFTFlashln(" %");
}
