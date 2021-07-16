#include "config.h"

DHT dht(DHTPIN, DHTTYPE);
OneWire oneWireObjeto(pinDatosDQ);
DallasTemperature sensorDS18B20(&oneWireObjeto);

float radiacion_valor = 0.0;
float humedad_valor =0.0;
char str_radiacion[20] = " ";
char str_lcd[20] = " ";

void setup() {

  Serial.begin(9600);
  dht.begin();
  sensorDS18B20.begin();
  
}

void loop() {
delay(5000);
  //Sensor radiacion
  radiacion_valor = getRadiationValue();
  Serial.println(radiacion_valor);

    //Sensor radiacion
  humedad_valor = getHumedadValor();
  Serial.println(humedad_valor);

  //SensorHumedadSuelo
  sensorDS18B20.requestTemperatures();
  Serial.println(sensorDS18B20.getTempCByIndex(0));

  //SensorHumedad y temperatura
  //delay(5000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.print("Error ");
    return;
      }
      Serial.print(h);
      Serial.println(t);
  
}
