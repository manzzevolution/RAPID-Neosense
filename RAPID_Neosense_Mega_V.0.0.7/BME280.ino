float getHumidity(){
  float humid = bme280.readFloatHumidity();
  SerialFlash("Humidity : ");Serial.print(humid);SerialFlashln(" % ");
  return humid;
}

float getTempC(){
  float tmp = bme280.readTempC();
  SerialFlash("Temperature: ");Serial.print(tmp);SerialFlashln(" 'C ");
  return tmp;
}

float getPressure(){
  float pressuree = bme280.readFloatPressure();
  SerialFlash("Pressure : ");Serial.print(pressuree);SerialFlashln(" Pa ");
  return pressuree;
}

void getBME280(){
  TFTFlashln("Get BME280 Data");
  temperature = getTempC();
  hum = getHumidity();
  pressure = getPressure();
}
