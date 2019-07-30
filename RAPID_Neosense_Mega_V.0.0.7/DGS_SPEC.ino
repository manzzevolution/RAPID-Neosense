void startSPECSensorSO2(){
  sensorSO2.flush();
  bool quit = false;
  String seriesData;
  SerialFlashln("Start Measuring SO2");
  TFTFlashln("Start Measuring SO2");
  sensorSO2.write('\r');
  waktuLama = millis();
  while ((!quit) && (millis() - waktuLama <= timeout)){
    if (millis() % 1000 == 0){
      sensorSO2.write('\r');
    }
    if (sensorSO2.available() > 0){
      char x = sensorSO2.read();
      if (x == '\n'){
        quit = true;
      } else {
        if (x != ' '){
          seriesData += x;
        }
      }
    }
  }
  SerialFlash("Raw Data : ");Serial.println(seriesData);
  SO2ppb = parsingData(seriesData);
}

void startSPECSensorNO2(){
  sensorNO2.flush();
  bool quit = false;
  String seriesData;
  SerialFlashln("Start Measuring NO2");
  TFTFlashln("Start Measuring NO2");
  sensorNO2.write('\r');
  waktuLama = millis();
  while ((!quit) && (millis() - waktuLama <= timeout)){
    if (millis() % 1000 == 0){
      sensorNO2.write('\r');
    }
    if (sensorNO2.available() > 0){
      char x = sensorNO2.read();
      if (x == '\n'){
        quit = true;
      } else {
        if (x != ' '){
          seriesData += x;
        }
      }
    }
  }
  SerialFlash("Raw Data : ");Serial.println(seriesData);
  NO2ppb = parsingData(seriesData);
}

void startSPECSensorCO(){
  sensorCO.flush();
  bool quit = false;
  String seriesData;
  SerialFlashln("Start Measuring CO");
  TFTFlashln("Start Measuring CO");
  sensorCO.write('\r');
  waktuLama = millis();
  while ((!quit) && (millis() - waktuLama <= timeout)){
    if (millis() % 1000 == 0){
      sensorCO.write('\r');
    }
    if (sensorCO.available() > 0){
      char x = sensorCO.read();
      if (x == '\n'){
        quit = true;
      } else {
        if (x != ' '){
          seriesData += x;
        }
      }
    }
  }
  SerialFlash("Raw Data : ");Serial.println(seriesData);
  COppb = parsingData(seriesData);
}

void startSPECSensorO3(){
  sensorO3.listen();
  sensorO3.flush();
  bool quit = false;
  String seriesData;
  SerialFlashln("Start Measuring O3");
  TFTFlashln("Start Measuring O3");
  sensorO3.write('\r');
  waktuLama = millis();
  while ((!quit) && (millis() - waktuLama <= timeout)){
    if (millis() % 1000 == 0){
      sensorO3.write('\r');
    }
    if (sensorO3.available() > 0){
      char x = sensorO3.read();
      if (x == '\n'){
        quit = true;
      } else {
        if (x != ' '){
          seriesData += x;
        }
      }
    }
  }
  SerialFlash("Raw Data : ");Serial.println(seriesData);
  O3ppb = parsingData(seriesData);
}


long parsingData (String text){
  //SerialFlashln("Parsing Data");
  String arrayData[11];
  int datake = 0;
  for(int i = 0; i < text.length();i++){
    if(text[i] != ','){
      arrayData[datake] += text[i];
    } else {
      datake++;
    }
  }
//  for checking data array
//  for(int i = 0; i < 11; i++){
//    Serial.print(i);SerialFlash(". ");Serial.println(arrayData[i]);
//  }
  return arrayData[1].toInt();
}
