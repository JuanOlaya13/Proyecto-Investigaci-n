#include "config.h"
#include <Arduino.h>
float getRadiacionValue(void){
  
float radiacion_valor = 0.0;
int radiacion_conver = 0.0;

radiacion_conver = analogRead(pin_sensor_radiacion);
radiacion_valor = radiacion_conver * 2.93255;

return radiacion_valor;
  }
