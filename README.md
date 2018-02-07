# ESP32_BME280_I2C
BME280 library for I2C interface ( for Arduino - ESP32 ).  
Beta ver1.2  
  
これはBOSCH製　温度・湿度・気圧センサー 用のI2C通信ライブラリです。  
Arduino core for ESP32 専用です。  
あまり精度が高いとは言えません。  
あくまで自己満足ライブラリです。  
本家 BOSCH ドライバーを使った方が無難ですよ。  
  
# Change log
(1.2)  
Add the following function of double type and add Read_All class.  
- compensate_T_double  
- compensate_P_double  
- compensate_H_double  
- Read_All  
  
(1.1)  
Inside the library, the place where the assignment of SCl and SDA was reversed has been corrected.  
  
【更新履歴】(Japanese)  
(1.2)  
double型の以下の関数を追加し、Read_Allクラスを追加。  
- compensate_T_double  
- compensate_P_double  
- compensate_H_double  
- Read_All  
  
(1.1)  
ライブラリ内部で、SCl と SDA のアサインがテレコになっていたところを修正しました。
  
  
# Credits and license
License MIT  
  
Reference My Blog：  
https://www.mgo-tec.com  