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
  Serial.println("---------------- Arduino en marche ------------------------");
  pinMode(lum, INPUT);
  pinMode(presence, INPUT);
  pinMode(gas_censor, INPUT);
  pinMode(buzzer, OUTPUT); // Définir le buzzer comme une sortie
  pinMode(LedV, OUTPUT);
  pinMode(LedJ, OUTPUT);
  pinMode(LedR, OUTPUT);
}

void loop() {
  float niv_lum = analogRead(lum);
  float niv_gas = analogRead(gas_censor);
  int mvt = digitalRead(presence);
  int temperature = 0;
  int humidity = 0;

  if (mvt == HIGH) {
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    oled.begin(&Adafruit128x64, I2C_ADDRESS);
    oled.setFont(Adafruit5x7);
    oled.clear();
    oled.set2X();
    oled.println("Bienvenue!");
    delay(10000);
    oled.clear();
  }

  digitalWrite(LedV, LOW); // S'assurer que la LED verte est éteinte par défaut
  digitalWrite(LedJ, LOW); // S'assurer que la LED jaune est éteinte par défaut
  digitalWrite(LedR, LOW); // S'assurer que la LED rouge est éteinte par défaut

  if (niv_gas < 300) {
    digitalWrite(LedV, HIGH);
  } else if (niv_gas >= 300 && niv_gas < 800) {
    digitalWrite(LedJ, HIGH);
  } else if (niv_gas >= 800) {
    digitalWrite(LedR, HIGH);
  }


  Serial.print("Niveau lumiere: ");
  Serial.println(niv_lum);

  Serial.print("Niveau gas: ");
  Serial.println(niv_gas);

  Serial.println("  "); //ligne blanche

 
  int result = dht11.readTemperatureHumidity(temperature, humidity);

  if (result == 0) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C\tHumidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Activer le buzzer si la température dépasse 25°C ou si le niveau de gaz est supérieur à 600
    if (temperature > 25 || niv_gas > 600) {
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
      delay(500); 
    }
  } else {
    // Print error message based on the error code.
    Serial.println(DHT11::getErrorString(result));
  }

  delay(300);
}
