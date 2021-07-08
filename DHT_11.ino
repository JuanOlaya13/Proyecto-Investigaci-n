#include <DHT.h>

#include <LiquidCrystal.h>

#define DHTPIN 2

#define DHTTYPE DHT11
 

DHT dht(DHTPIN, DHTTYPE);

const int rs = 22, en =23, d4 = 24, d5 = 25, d6 = 26, d7=27;

LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

void setup(void) {
 
  lcd.begin(20,4);
  dht.begin();
 
}
 
void loop() {
  
  delay(5000);
  lcd.clear();

  
  float h = dht.readHumidity();
 
  
  
  float t = dht.readTemperature();
  
   
  
 if (isnan(h) || isnan(t)) {
    lcd.write("Error ");
    return;
  }
  
  
  lcd.print("Humedad: ");
  lcd.print(h);
  lcd.print(" %\t");
  lcd.setCursor(0,2);
  lcd.print("Temperatura: ");
  lcd.print(t);
  lcd.print(" C ");
   
}
