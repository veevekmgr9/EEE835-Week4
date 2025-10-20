int pin = A0;

void setup() {
  Serial.begin(9600);
  while(!Serial);
}

void loop() {
  uint16_t rawADC = analogRead(pin);
  float voltage = 3.3*rawADC/1023.0;

  Serial.print("ADC Value = ");
  Serial.print(rawADC);
  Serial.println(".");

  Serial.print("Voltage = ");
  Serial.println(voltage);
  Serial.println(" V.");

  delay(1000);
}
