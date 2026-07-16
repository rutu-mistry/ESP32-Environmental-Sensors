#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Define your ESP32-S3 I2C pins
#define I2C_SDA 8
#define I2C_SCL 9

// Create the BME280 object using I2C
Adafruit_BME280 bme; 

void setup() {
  Serial.begin(115200);
  while(!Serial); // Wait for serial monitor to open
  
  // Initialize I2C with your custom ESP32-S3 pins
  Wire.begin(I2C_SDA, I2C_SCL); 

  Serial.println(F("BME280 Temperature & Humidity Test"));

  // Most BME280 I2C modules use address 0x76. If it fails, change to 0x77.
  if (!bme.begin(0x76, &Wire)) {
    Serial.println("Could not find a valid BME280 sensor! Check wiring or I2C address.");
    while (1);
  }

  Serial.println("BME280 sensor found successfully!");
}

void loop() { 
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println("------------------------------------");
  delay(2000); // Read data every 2 seconds
}
