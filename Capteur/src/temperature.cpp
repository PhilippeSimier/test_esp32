#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 18   // Gpio 18 sur la carte clavier SNIR
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {

    // Démarre la liaison série 115200 bauds prise USB
    Serial.begin(115200);
    while (!Serial);

    sensors.begin();
    Serial.print("Trouvé ");
    Serial.print(sensors.getDeviceCount(), DEC);
    Serial.println(" capteur(s).");
    

}

void loop() {

    sensors.requestTemperatures();
    float temperatureC = sensors.getTempCByIndex(0);
    float temperatureF = sensors.getTempFByIndex(0);
    Serial.print(temperatureC);
    Serial.print(" ºC : ");
    Serial.print(temperatureF);
    Serial.println(" ºF");
    delay(5000);

}
