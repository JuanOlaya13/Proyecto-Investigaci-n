#include "config.h"
float getVelViento(volatile int windCont) {
   int timeWindSpeed = 120;
   
  float windSpeed = (windCont) * 2.4 / timeWindSpeed;
  return windSpeed;

}
