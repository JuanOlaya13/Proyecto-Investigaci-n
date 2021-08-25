#include "config.h"


//RECORDAR LA FORMULA QUE NOS DEJO EL PROFESOR CARLOS PINEDO EN EL DRIVE PARA CALCULAR OTRA VARIABLE


DHT dht(DHTPIN, DHTTYPE);
OneWire oneWireObjeto(pin_sensor_temp_suelo);
DallasTemperature sensorDS18B20(&oneWireObjeto);
SFE_BMP180 bmp180;
RTC_DS3231 rtc;


String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
float radiacion_valor = 0.0;
float humedad_valor = 0.0;
int timeWindSpeed = 120;
double windDirection = 0;
double preci_actual = 0;
volatile int windCont = 0; //Variable volatil para la interrupción d velocidad de viento
volatile int rainCont = 0; //Variable volatil para la interrupción de precipitacion
const int Banda = 150;
long int Marca_tiempo = 10000;
const int aumento = 10000;
long windTime = 0;
long rainTime = 0;
long Time2 = 1000;
long Time3 = 4000;
int envio = 0; 

void setup() {

  pinMode(windPulsePin, INPUT_PULLUP);
  pinMode(rainPulsePin, INPUT_PULLUP);
  Serial.begin(9600);
  bmp180.begin();
  dht.begin();
  sensorDS18B20.begin();
  attachInterrupt(digitalPinToInterrupt(windPulsePin), windCounterInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(rainPulsePin), rainCounterInterrupt, FALLING);

  if (!rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }

  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void printDate(DateTime date)
{
  Serial.print(date.year(), DEC);
  Serial.print('/');
  Serial.print(date.month(), DEC);
  Serial.print('/');
  Serial.print(date.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[date.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(date.hour(), DEC);
  Serial.print(':');
  Serial.print(date.minute(), DEC);
  Serial.print(':');
  Serial.print(date.second(), DEC);
  Serial.println();
}

void rainCounterInterrupt() {
  if (millis() - rainTime > Banda) {
    rainCont++;
    rainTime = millis();
    if(rainCont==1){
    preci_actual = getPrecipitacion(rainCont, preci_actual);
    Serial.print("Prec: ");
    Serial.print (preci_actual);
    Serial.println("mm");
      
    }
  }
}

void windCounterInterrupt()
{
  //   Debounce o Antirebote por código
  if (millis() - windTime > Banda)
  {

    windCont++;
    windTime = millis();
  }
}

void loop() {
  DateTime now = rtc.now();
  //printDate(now);
     
  if ((now.minute() % 2 == 0) && (envio != 1)) {
    envio = 1;
//    Sensor radiacion
  Serial.print("Radiation: ");
  radiacion_valor = getRadiationValue();
  Serial.print(radiacion_valor);
  Serial.println("W/m^2 ");

  //Sensor Humedad del Suelo
   Serial.print("Humedad Suelo: ");
  humedad_valor = getHumedadValor();
  Serial.print(humedad_valor);
   Serial.println("%");

  //Sensor de Temperatura de Suelo
   Serial.print("Tempertatura Suelo: ");
  sensorDS18B20.requestTemperatures();
  Serial.print(sensorDS18B20.getTempCByIndex(0));
   Serial.println("°C");

  //Sensor Humedad y Temperatura ambiente
    float h = dht.readHumidity();
    float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.print("Error ");
    return;
  }
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Tempertatura: ");
  Serial.print(t);
  Serial.println("°C");

  //sensorVelViento
    Serial.print("Vel: ");
    Serial.print(getVelViento(windCont));
    Serial.println("Km/h");
    windCont = 0;
    
  //sensorDirViento
  /*
    Serial.print("DirViento: ");
    Serial.println(getDirViento());
 */
  //3sensorPrecipitacion
    preci_actual = getPrecipitacion(rainCont, preci_actual);
    Serial.print("Prec: ");
    Serial.print (preci_actual);
    Serial.println("mm");
    rainCont = 0;
    (getPrecipitacion(rainCont, preci_actual));
   
    
  //Sensor de presion atmosferica
   char status;
    double T, P;
    status = bmp180.startTemperature();//Inicio de lectura de temperatura
    if (status != 0)
    {
      delay(status); //Pausa para que finalice la lectura
      status = bmp180.getTemperature(T); //Obtener la temperatura
      if (status != 0)
      {
        status = bmp180.startPressure(3); //Inicio lectura de presión
        if (status != 0)
        {
          delay(status);//Pausa para que finalice la lectura
          status = bmp180.getPressure(P, T); //Obtenemos la presión
          if (status != 0)
          {

            Serial.print("Presion: ");
            Serial.print(P);
            Serial.println(" mb");
          }
        }
      }
    }
    



  }else if ((now.minute() % 2 != 0) && (envio != 0)){
  envio=0;
  }
  



}
