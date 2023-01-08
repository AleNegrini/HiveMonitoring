/** WARNING **/
/** This code is under development and it is not reliable yet: it will be heavily refactored in the next days **/

#include <DHT.h>;                   // include the DHT library (remind to install it before compiling) 

#define EXT_DHTPIN 2
#define INT_DHTPIN 3
#define EXT_DHTTYPE DHT22
#define INT_DHTTYPE DHT22

#define SAMPLING_FREQUENCY_SEC 60

DHT ext_dht(EXT_DHTPIN, EXT_DHTTYPE);
DHT int_dht(INT_DHTPIN, INT_DHTTYPE);

// Variables
float ext_humidity;
float int_humidity;
float ext_tempC;
float int_tempC;

void setup() {
  Serial.begin(9600);
  ext_dht.begin();
  int_dht.begin();
}

void loop() {
  delay(SAMPLING_FREQUENCY_SEC*1000);
  // Read data and store it to variables humidity and temp from the external and internal sensors
  ext_humidity = ext_dht.readHumidity();
  ext_tempC = ext_dht.readTemperature();
  int_humidity = int_dht.readHumidity();
  int_tempC = int_dht.readTemperature();

  // Check if any reads failed from internal and external DHT sensors
  if(isnan(ext_humidity) || isnan(ext_tempC)) {
    Serial.println("Failed to read data from the external DHT sensor");
  } else {
    Serial.print("External Humidity: ");
    Serial.print(ext_humidity);
    Serial.print("%");

    Serial.print(" | "); 
  
    Serial.print("External Temperature: ");
    Serial.print(ext_tempC);
    Serial.println("°C");
  }
  if(isnan(int_humidity) || isnan(int_tempC)) {
    Serial.println("Failed to read data from the internal DHT sensor");
  } else {
    Serial.print("Internal Humidity: ");
    Serial.print(int_humidity);
    Serial.print("%");

    Serial.print(" | "); 
  
    Serial.print("Internal Temperature: ");
    Serial.print(int_tempC);
    Serial.println("°C");
  }


}
