#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SFE_BMP180.h>
#include <Wire.h>
#include "RTClib.h"


#define DHTPIN 4

#define DHTTYPE DHT11


 
const byte windPulsePin = 2;
const byte rainPulsePin = 3;

const int pin_sensor_radiacion = A13;
const int pin_sensor_humedad_suelo = A0;
const int pin_sensor_dirviento = A1;
const int pin_sensor_temp_suelo = 5;

float getTime (String daysOfTheWeek[7],String monthsNames[12]);
float getPrecipitacion (volatile int Cont, double preci_actual);
float getRadiationValue(void);
float getHumedadValor(void);
float getPresion(void);
float getVelViento(volatile int windCont);
double getDirViento(void);
