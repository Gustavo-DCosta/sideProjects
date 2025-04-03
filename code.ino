#include <Arduino.h>
#include "DHT11.h"

const int led_exterieur = 2;   
const int presence = A3;         
const int sensor = A0;
const int buzzer = 3;
const int temp = A1;

float gas;

DHT11 dht11(4);


void setup() {

  Serial.begin(9600);

  pinMode(sensor, INPUT);
  pinMode(presence, INPUT); 
  pinMode(buzzer, OUTPUT);   
  pinMode(led_exterieur, OUTPUT);  
  pinMode(temp, INPUT);

  Serial.println("-------------------Arduino en marche-------------------------");
 
}
void loop() {
  gas = analogRead(sensor);
  Serial.println("capteur gas");
  Serial.println(gas);
  
  float temperature = analogRead(temp);
  float Humidity = dht11.readHumidity();

  Serial.print("Humidity: ");
  Serial.print(Humidity);
  Serial.println(" %");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C");

  int presence_ok = digitalRead(presence); 

  if (presence_ok == HIGH) {  
    digitalWrite(led_exterieur, HIGH); 
    delay(5000);
   // digitalWrite(3, HIGH);
    //delay(analogRead(0));
    //digitalWrite(3, LOW);

  }
  else {
    digitalWrite(led_exterieur, LOW);  
  }

  delay(300);  
}
