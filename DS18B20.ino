#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

const int pinDatosDQ = 3;
const int rs = 22, en =23, d4 = 24, d5 = 25, d6 = 26, d7=27;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);
OneWire oneWireObjeto(pinDatosDQ);
DallasTemperature sensorDS18B20(&oneWireObjeto);
void setup() {
  
  lcd.begin(20,4);
  sensorDS18B20.begin();
}
void loop() {
  lcd.clear();
  sensorDS18B20.requestTemperatures();
  lcd.print("Temperatura: ");
  lcd.print(sensorDS18B20.getTempCByIndex(0));
  lcd.print(" C");
  
  delay(1000);
}
