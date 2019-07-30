String getDataFromMega(){
  bool quit = false;
  String seriesData;
  SerialFlashln("Waiting data from Mega");
  waktuLama = millis();
  while ((!quit) && (millis() - waktuLama <= timeout)){
    if (millis() % 1000 == 0){
      SerialFlash(".");
      digitalWrite(pinLED,!(digitalRead(pinLED)));
      delay(1);
    }
    if (SerialMega.available() > 0){
      char x = SerialMega.read();
      if (x == '\n'){
        quit = true;
      } else {
        if (x != ' '){
          seriesData += x;
        }
      }
    }
  }
  if (millis() - waktuLama >= timeout){
    cekTimeout = true;
  } else {
    cekTimeout = false;
  }
  Serial.println();
  SerialFlash("Raw Data : ");Serial.print(seriesData);SerialFlash(" Timeout Checker: ");Serial.println(cekTimeout);
  return seriesData;
}

void parsingData (String text){
  //SerialFlashln("Parsing Data");
  String arrayData[20];
  jumlahKoma = 0;
  int datake = 0;
  for(int i = 0; i < text.length();i++){
    if (text[i] != ','){
      arrayData[datake] += text[i];
    } else {
      datake++;
      jumlahKoma++;
    }
  }
//  for checking data array
  for(int i = 0; i < 11; i++){
    Serial.print(i+1);SerialFlash(". ");Serial.println(arrayData[i]);
  }
  SO2ppb = arrayData[0].toFloat();
  NO2ppb = arrayData[1].toFloat();
  COppb = arrayData[2].toFloat();
  O3ppb = arrayData[3].toFloat();
  PM1 = arrayData[4].toFloat();
  PM25 = arrayData[5].toFloat();
  PM10 = arrayData[6].toFloat();
  temperature = arrayData[7].toFloat();
  hum = arrayData[8].toFloat();
  pressure = arrayData[9].toFloat();
}
