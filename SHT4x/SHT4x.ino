#include <Wire.h>
#include <Adafruit_SHT4x.h>

#define SDA_PIN 8
#define SCL_PIN 9

Adafruit_SHT4x sht4 = Adafruit_SHT4x();

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Initialize I2C
  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println("Initializing SHT45...");

  if (!sht4.begin(&Wire)) {
    Serial.println("Could not find SHT45 sensor!");
    while (1) {
      delay(10);
    }
  }

  Serial.println("SHT45 Found!");

  // Optional settings
  sht4.setPrecision(SHT4X_HIGH_PRECISION);
  sht4.setHeater(SHT4X_NO_HEATER);
}

void loop() {

  sensors_event_t humidity, temperature;

  if (!sht4.getEvent(&humidity, &temperature)) {
    Serial.println("Failed to read sensor");
    delay(1000);
    return;
  }

  Serial.print("Temperature : ");
  Serial.print(temperature.temperature);
  Serial.println(" °C");

  Serial.print("Humidity    : ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" %");

  Serial.println("------------------------");

  delay(2000);
}