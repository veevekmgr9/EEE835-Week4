int tmp36 = A0;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  analogReadResolution(12);
}

void loop() {
  uint16_t rawADC = analogRead(tmp36);
  float voltage = 3.3*rawADC/4095.0;
  float temperature = (voltage - 0.5)*100;

  Serial.print("Room Temperature = ");
  Serial.print(temperature);
  Serial.println(" Degree Celcius.");

  delay(1000);
}
