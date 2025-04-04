#include <DHT11.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"
#define I2C_ADDRESS 0x3C
SSD1306AsciiAvrI2c oled;

const int lum = A0;
const int presence = A1;
const int gas_censor = A2;

const int led_ext = 3; 
const int LedJ = 7;
const int LedV = 8;
const int LedR = 6;

const int buzzer = 4;

DHT11 dht11(2);

void setup() {
  Serial.begin(9600);
  Serial.pritln("---------------- Arduino en marche ------------------------")
  pinMode(lum, INPUT);
  pinMode(presence, INPUT);
  pinMode(gas_censor, INPUT);
}

void loop() {
  float niv_lum = analogRead(lum);
  float niv_gas = analogRead(gas_censor);
  int mvt = digitalRead(presence);
  int temperature = 0;
  int humidity = 0;

  if (mvt == HIGH) {
    digitalWrite(4, HIGH);
    delay(200);
    digitalWrite(4, LOW);
    oled.begin(&Adafruit128x64, I2C_ADDRESS);
    oled.setFont(Adafruit5x7);  
    oled.clear();
    oled.set2X();
    oled.println("Bienvenue!");
    delay(10000);
    oled.clear();
  }

  while (niv_gas < 300) {
    digitalWrite(ledV, HIGH);

    if (niv_gas >= 300) {
      digitalWrite(LedJ, HIGH);
    }
    else if (niv_gas >=800) {
      digitalWrite(LedR, HIGH);
    }
  }


  Serial.print("Niveau lumiere: ");
  Serial.println(niv_lum);

  Serial.print("Niveau gas: ");
  Serial.println(niv_gas);

  Serial.println("  "); //ligne blacnhe

    // Attempt to read the temperature and humidity values from the DHT11 sensor.
  int result = dht11.readTemperatureHumidity(temperature, humidity);

    // Check the results of the readings.
    // If the reading is successful, print the temperature and humidity values.
    // If there are errors, print the appropriate error messages.
  if (result == 0) {
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.print(" °C\tHumidity: ");
      Serial.print(humidity);
       Serial.println(" %");
  } else {
      // Print error message based on the error code.
      Serial.println(DHT11::getErrorString(result));
  }

  delay(300);
}