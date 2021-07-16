#include "config.h"
float getRadiationValue(void) {
  
  float radiacion_valor = 0.0;
  int radiacion_conver = 0.0;
  radiacion_conver = analogRead(A13);
  radiacion_valor = radiacion_conver * 2.93255;

  return radiacion_valor;

}
