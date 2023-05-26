#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "model.h"
#include "DHT.h"
#include <EloquentTinyML.h>
#define DHTTYPE DHT11  
#define DHTPIN 2     
DHT dht(DHTPIN, DHTTYPE);


Eloquent::ML::Port::SVM Temp_Hum;//instanciate the classifier object 
void setup() {
  Serial.begin(9600);//begin the Serial communication
  dht.begin();
  Wire.begin(); //begin the I2C communication
}

void loop() {
  // put your main code here, to run repeatedly:
   float temp= dht.readTemperature();
 float humid=dht.readHumidity();

 float features[]={temp,humid};
String output_str = Temp_Hum.predictLabel(features); //run inference
  Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.print(" Humidity : ");
  Serial.println(humid);
 Serial.println(output_str);//print the resulting orientation
}