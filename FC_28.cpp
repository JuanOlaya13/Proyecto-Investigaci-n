#include "config.h"
float getHumedadValor(void) {
  
  float humedad_valor = 0.0;
  int humedad_conver = 0.0;
  humedad_conver = analogRead(A0);
  humedad_valor = humedad_conver * 0.09765625;

  return humedad_valor;

}
