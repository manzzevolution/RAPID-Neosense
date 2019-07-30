void Winsen_ZH03A(bool debug){
  Winsen_Port.listen();
  int PM01Value = 0;  //define PM1.0 value of the air detector module
  int PM25Value = 0;  //define PM2.5 value of the air detector module
  int PM10Value = 0;  //define PM10 value of the air detector module
  
  //PRINT(F("Get Winsen ZH03A Data"));
  if(Winsen_Port.find(0x42)){    
    Winsen_Port.readBytes(zh03_buf,PMDataLength);    
    if(zh03_buf[0] == 0x4d){
      PM01Value = transmitPM01(zh03_buf);  //count PM1.0 value of the air detector module
      PM25Value = transmitPM25(zh03_buf);  //count PM2.5 value of the air detector module
      PM10Value = transmitPM10(zh03_buf);  //count PM10 value of the air detector module        
    }           
  }
  //-- Convert to PPM
  if(debug){
    for(int i = 0;i < PMDataLength;i++){
      Serial.print(i);Serial.print(".0x");Serial.print(zh03_buf[i],HEX);Serial.print("|");
    }
  }
  PM1 = PM01Value * adjustment;
  PM25 = PM25Value * adjustment;
  PM10 = PM10Value * adjustment;
}

int transmitPM01(unsigned char *thebuf){
  int PM01Val;
  //-- Count PM1.0 value of the air detector module
  PM01Val=((thebuf[4]<<8) + thebuf[5]); 
  return PM01Val;
}

//-- transmit PM Value to Serial Monitor
int transmitPM25(unsigned char *thebuf){
  int PM25Val;
  //-- Count PM2.5 value of the air detector module
  PM25Val=((thebuf[6]<<8) + thebuf[7]);
  return PM25Val;
}

//-- transmit PM Value to Serial Monitor
int transmitPM10(unsigned char *thebuf){
  int PM10Val;
  //-- Count PM10 value of the air detector module  
  PM10Val=((thebuf[8]<<8) + thebuf[9]); 
  return PM10Val;
}
