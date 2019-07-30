
// ------------------- Basic Init ----------------------------
#define SerialFlashln(x) Serial.println(F(x))
#define SerialFlash(x) Serial.print(F(x))
#define TFTFlashln(x) tft.println(F(x))
#define TFTFlash(x) tft.print(F(x))

#define pinPump A0
#define pinInterrupt 2
#define timeUpload 300
#define pinLED 13 

#include "SoftwareSerial.h" //Include the next lines if using Arduino without mySerial support, and replace refernces to mySerial with mySerial
#include <TimerOne.h>

SoftwareSerial SerialESP(53,52);  // Tx pin

// ------------------- Basic End -----------------------------

// ------------------- SPEC Sensor Init ----------------------

#define sensorNO2 Serial1
#define sensorSO2 Serial2
#define sensorCO  Serial3
SoftwareSerial sensorO3(11, 12); // !!! RX, TX Must be on 3.3 volt communication, or using level shifters to get to 3.3V UART!!!


#define timeout 10000
int timing = 300; //set the moving average
long SO2ppb,NO2ppb,COppb,O3ppb;
unsigned long waktuLama;

// ------------------- SPEC Sensor End ----------------------
// ------------------- BME280 Init --------------------------

#include <Wire.h>
#include "SparkFunBME280.h"
BME280 bme280; //Uses default I2C address 0x77
float temperature,hum,pressure;
// ------------------- BME280 End ---------------------------

// ------------------------------------ Winsen ZH03A Init ------------------------------------------

#define PMDataLength  31   //0x42 + 31 bytes equal to 32 bytes
SoftwareSerial Winsen_Port(50, 51); // RX, TX
unsigned char zh03_buf[PMDataLength];
float adjustment = 0.001;
float PM1,PM25,PM10;
// ------------------------------------ End Winsen ZH03A ------------------------------------------

// ------------------------------------ TFT SPI Init ---------------------------------------------
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#define cs   4 //CS
#define sclk 5 //SCK
#define mosi 6 //SDA
#define dc   7 //A0
#define rst  8 //RESET

Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, mosi, sclk, rst);

// ------------------------------------ TFT SPI End ----------------------------------------------
