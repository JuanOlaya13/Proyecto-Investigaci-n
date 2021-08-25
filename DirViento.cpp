#include "config.h"
double getDirViento(void) {

  double x=analogRead(A1);
  x=x*5/1024;
  double x2=x*x;
  double x3=x*x*x;
  double x4=x*x*x*x;
  double x5=x*x*x*x*x;
  double x6=x*x*x*x*x*x;
  double dirViento= 0.000006*x6 - 0.0004*x5 + 0.0091*x4 - 0.0979*x3 + 0.6509*x2 - 2.7967*x + 6.0087; 
  return x;

}
