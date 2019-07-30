void sendToSerial(String text){
  SerialESP.listen();
  TFTFlashln("Sending");
  tft.println(text);
  for(int v = 0 ; v <= 5; v++){
    SerialFlash("Sent ! ");Serial.print(v);SerialFlash(". ");Serial.println(text);
    SerialESP.println(text);
    delay(500);
  }
  TFTFlashln("Done");
}

String combineAllText(){
  String textTemp = "";
  textTemp = String(SO2ppb) + "," + String(NO2ppb) + "," + String(COppb) + "," + String(O3ppb) + "," + 
             String(PM1) + "," + String(PM25) + "," + String(PM10) + "," + String(temperature) + "," +
             String(hum) + "," + String(pressure);
  return textTemp;
}
