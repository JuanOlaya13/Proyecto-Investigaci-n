#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define DHTPIN 2

#define DHTTYPE DHT11

const int pin_sensor_radiacion = A13;
const int pin_sensor_humedad = A0;
const int pinDatosDQ = 3;



float getRadiationValue(void);
float getHumedadValor(void);
