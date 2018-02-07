#include "ESP32_BME280_I2C.h"

const uint8_t Address = 0x76;
const uint8_t sda = 5;
const uint8_t scl = 26;
const uint32_t frequency = 30000;

ESP32_BME280_I2C bme280i2c(Address, scl, sda, frequency);

void setup(){
  Serial.begin(115200);
  delay(1000); //Take some time to open up the Serial Monitor

  //Example Indoor navigation
  uint8_t t_sb = 0; //stanby 0.5ms
  uint8_t filter = 4; //IIR filter = 16
  uint8_t osrs_t = 2; //OverSampling Temperature x2
  uint8_t osrs_p = 5; //OverSampling Pressure x16
  uint8_t osrs_h = 1; //OverSampling Humidity x1
  uint8_t Mode = 3; //Normal mode

  bme280i2c.ESP32_BME280_I2C_Init(t_sb, filter, osrs_t, osrs_p, osrs_h, Mode);
  delay(1000);
}

void loop(){
  bme_get();
  delay(5000);
}

//************** BME280 measure *************************
void bme_get(){ 
  double temperature, pressure, humidity;

  bme280i2c.Read_All(&temperature, &pressure, &humidity);

  char temp_c[10], hum_c[10], pres_c[10];
  sprintf(temp_c, "%2.2lf", temperature);
  sprintf(hum_c, "%2.2lf", humidity);
  sprintf(pres_c, "%4.2lf", pressure);

  Serial.println("-----------------------");
  Serial.print("Temperature = "); Serial.println(temp_c);
  Serial.print("Humidity = "); Serial.println(hum_c);
  Serial.print("Pressure = "); Serial.println(pres_c);
  Serial.println("-----------------------");
  Serial.flush();
}
