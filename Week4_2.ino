// Define analog input pin connected to TMP36 temperature sensor output
int tmp36 = A0;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  // Wait for serial monitor to open
  while(!Serial);
  // Set ADC resolution to 12 bits
  analogReadResolution(12);
}
void loop() {
  // Read the analog value from the TMP36 sensor
  uint16_t rawADC = analogRead(tmp36);
  // Convert ADC value to voltage
  float voltage = 3.3 * rawADC / 4095.0;
  // Convert voltage to temperature in Celsius
  float temperature = (voltage - 0.5) * 100;
  // Print temperature value to the Serial Monitor
  Serial.print("Room Temperature = ");
  Serial.print(temperature);
  Serial.println(" Degree Celsius.");
  // Wait for 1 second before next reading
  delay(1000);
}
