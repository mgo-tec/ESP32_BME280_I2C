/*
  ESP32_BME280_I2C.h - for Arduino core for ESP32
  Beta version 1.2
  
License MIT [Modified person is Mgo-tec.]

Reference SWITCH SCIENCE page URL:
http://trac.switch-science.com/wiki/BME280

Reference library:
https://github.com/adafruit/Adafruit_BME280_Library

Original License is BSD [Copyright (c) 2012, Adafruit Industries]

BSD License:
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holders nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef ESP32_BME280_I2C_h_
#define ESP32_BME280_I2C_h_

#include "Arduino.h"
#include "Wire.h"

class ESP32_BME280_I2C
{
public:
  ESP32_BME280_I2C(uint8_t bme280_address, uint8_t scl, uint8_t sda, uint32_t freq);

  void ESP32_BME280_I2C_Init(uint8_t Stanby_t, uint8_t filter, uint8_t overS_T, uint8_t overS_P, uint8_t overS_H, uint8_t mode);
  void WriteRegister(uint8_t reg_address, uint8_t data);
  void ReadCalibration(void);
  double Read_Temperature();
  double Read_Pressure();
  double Read_Humidity();

  void Read_All(double *temp, double *press, double *hum);
  double ReadAltitude(double SeaLevel_Pres, double pressure);

  int32_t compensate_T(int32_t adc_T);
  double compensate_T_double(int32_t adc_T);

  uint32_t compensate_P(int32_t adc_P);
  double compensate_P_double(int32_t adc_P);

  uint32_t compensate_H(int32_t adc_H);
  double compensate_H_double(int32_t adc_H);

  uint16_t read16bit(uint8_t reg);
  uint8_t read8bit(uint8_t reg);

private:
  uint8_t _bme280_addres;
  uint8_t _scl, _sda;
  uint32_t _freq;

  int32_t _t_fine;

  uint16_t _dig_T1;
   int16_t _dig_T2;
   int16_t _dig_T3;

  uint16_t _dig_P1;
   int16_t _dig_P2;
   int16_t _dig_P3;
   int16_t _dig_P4;
   int16_t _dig_P5;
   int16_t _dig_P6;
   int16_t _dig_P7;
   int16_t _dig_P8;
   int16_t _dig_P9;

  uint8_t  _dig_H1;
   int16_t _dig_H2;
  uint8_t  _dig_H3;
   int16_t _dig_H4;
   int16_t _dig_H5;
   int8_t  _dig_H6;
};

#endif