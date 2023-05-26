#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "model.h"
#include "DHT.h"
#include <EloquentTinyML.h>
#define DHTTYPE DHT11  
#define DHTPIN 2     
DHT dht(DHTPIN, DHTTYPE);


const int dryValue = 700;   //you need to replace this value with Value_1
const int wetValue = 300;
float soilMoistureValue = 0;
float soilmoisturepercent = 0;

Eloquent::ML::Port::SVM Soil_Temp_Hum;//instanciate the classifier object 
void setup() {
  Serial.begin(9600);//begin the Serial communication
  dht.begin();
  Wire.begin(); //begin the I2C communication
}

void loop() {
  // put your main code here, to run repeatedly:
    // put your main code here, to run repeatedly:

       float temp= dht.readTemperature();
 float humid=dht.readHumidity();
  float soilMoistureValue = analogRead(A0);

  float features[]={temp,humid,soilMoistureValue};
  String output_str = Soil_Temp_Hum.predictLabel(features); //run inference
    Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.print(" Humidity : ");
  Serial.println(humid);
Serial.print("your soil moisture : ");
 Serial.println(soilMoistureValue);
 
Serial.println(output_str);//print the resulting orientation
}