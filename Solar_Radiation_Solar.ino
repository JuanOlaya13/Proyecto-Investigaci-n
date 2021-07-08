#include "config.h"
#include <LiquidCrystal.h>

const int rs = 5, en =4, d4 = 3, d5 = 2, d6 = 1, d7=0;

LiquidCrystal lcd (rs, en, d4, d5, d6, d7);


float radiacion_valor = 0.0;
char str_radiacion[20] = " ";
char str_lcd[20] = " ";
void setup() {

lcd.begin(20,4);
  
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  radiacion_valor = getRadiacionValue();
  dtostrf(radiacion_valor,4,2,str_radiacion);
  sprintf(str_lcd,"W/m2: %s",str_radiacion);
  lcd.print(str_lcd);
    //lcd.print("Radiacion: ");
  //lcd.print(radiacion_valor);
  //lcd.setCursor(0,1);
 // lcd.print(" W/m^2");
 
  delay(20);

}
