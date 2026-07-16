#include <Wire.h>
#include <Adafruit_AHTX0.h>

// Create an instance of the AHT20 sensor
Adafruit_AHTX0 aht;

void setup() {
  // Initialize Serial Monitor at 115200 baud rate
  Serial.begin(115200);
  while (!Serial) delay(10); // Wait for serial monitor to open

  Serial.println("--- ESP32 AHT20 Sensor Test ---");

  // Initialize I2C communication with ESP32 default pins (SDA:21, SCL:22)
  Wire.begin(8, 9);
  Serial.println("SDA:8, SCL:9 worked; IO9-Red(SCL),IO8-Brown(SDA)");

  // Attempt to initialize the AHT20 sensor
  if (!aht.begin()) {
    Serial.println("Error: Could not find AHT20 sensor! Check your wiring.");
    while (1) {
      delay(10); // Halt execution if sensor is missing
    }
  }
  
  Serial.println("AHT20 sensor successfully initialized!");
}

void loop() {
  // Create sensor event containers
  sensors_event_t humidity, temp;
  
  // Read current data from the sensor
  aht.getEvent(&humidity, &temp);

  // Print results to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temp.temperature, 2);
  Serial.println(" °C");

  Serial.print("Humidity:    ");
  Serial.print(humidity.relative_humidity, 2);
  Serial.println(" % rH");

  Serial.println("--------------------------------");

  // Wait 2 seconds before taking the next reading
  delay(2000);
}
