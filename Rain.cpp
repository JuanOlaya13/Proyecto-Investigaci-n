#include "config.h"

float getPrecipitacion(volatile int rainCont,double preci_actual) {
  
  double preci_temp = 0;

  preci_temp = rainCont * 0.2794;

  if (preci_temp == 0) {
    preci_actual = 0;

  }
  else {
    preci_actual =preci_actual + preci_temp;
    

  }
  return preci_actual;
}
