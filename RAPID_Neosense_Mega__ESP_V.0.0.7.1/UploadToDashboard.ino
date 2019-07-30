void UploadToDashboard(){
  // Connect or reconnect to WiFi
  Serial.println(F("Upload to Sensync Dashboard"));
  delay(2000);
  Serial.println(F("Connect to WiFi"));
  delay(500);
  if(WiFi.status() != WL_CONNECTED){
    Serial.print(F("Attempting to connect to SSID: "));
    Serial.println(SECRET_SSID);
    int n = 1;
    while((WiFi.status() != WL_CONNECTED) && (n <= retry)){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    getIPWiFi();
  } else {
    Serial.println(F("Already Connected"));
    getIPWiFi();
  }

  httpPhase();
  httpPhase2();
}
void httpPhase(){
  HTTPClient http;    //Declare object of class HTTPClient
  String Link;
  String dataString[3];
  dataString[0] = "http://secure.getsensync.com/neosense/data/?id=" + String(idSensync) + "&uid=" + String(uidSensync);
  dataString[1] = "&cogas=" + String(COppb) + "&o3gas=" + String(O3ppb) + "&so2gas=" + String(SO2ppb) + "&no2gas=" + String(NO2ppb);
  dataString[2] = "&pm1=" + String(PM1) + "&pm25=" + String(PM25) + "&pm10=" + String(PM10) + "&temp=" + String(temperature) + "&rhum=" + String(hum) + "&press=" + String(pressure) + "";
  Link = dataString[0] + dataString[1] + dataString[2];
  Serial.println(F("Link Set.."));
  http.begin(Link);     //Specify request destination
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload
  Serial.println(Link);
  Serial.print(F("HTTP return code: "));
  Serial.println(httpCode);   //Print HTTP return code
  Serial.print(F("Response: "));
  Serial.println(payload);    //Print request response payload
  if (payload.indexOf(confirmResponse) > 0){
    SerialFlashln("Success");
    delay(2000);
  } else {
    SerialFlashln("Failed");
    delay(2000);
  }
  //http.end();     //Close connection
}
void httpPhase2(){
  HTTPClient http;    //Declare object of class HTTPClient
  String Link;
  String dataString[3];
  dataString[0] = "http://128.199.194.1/neosense/data/?id=" + String(idSensync) + "&uid=" + String(uidSensync);
  dataString[1] = "&cogas=" + String(COppb) + "&o3gas=" + String(O3ppb) + "&so2gas=" + String(SO2ppb) + "&no2gas=" + String(NO2ppb);
  dataString[2] = "&pm1=" + String(PM1) + "&pm25=" + String(PM25) + "&pm10=" + String(PM10) + "&temp=" + String(temperature) + "&rhum=" + String(hum) + "&press=" + String(pressure) + "";
  Link = dataString[0] + dataString[1] + dataString[2];
  Serial.println(F("Link Set.."));
  http.begin(Link);     //Specify request destination
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload
  Serial.println(Link);
  Serial.print(F("HTTP return code: "));
  Serial.println(httpCode);   //Print HTTP return code
  Serial.print(F("Response: "));
  Serial.println(payload);    //Print request response payload
  if (payload.indexOf(confirmResponse) > 0){
    SerialFlashln("Success");
    delay(2000);
  } else {
    SerialFlashln("Failed");
    delay(2000);
  }
  //http.end();     //Close connection
}
void getIPWiFi(){
    IPAddress myIP = WiFi.localIP();
    String ipStr = String(myIP[0])+"."+String(myIP[1])+"."+String(myIP[2])+"."+String(myIP[3]);    
    Serial.println(F("WiFi connected"));
    Serial.println(F("IP address: "));
    Serial.println(WiFi.localIP());
    delay(2000);
}
