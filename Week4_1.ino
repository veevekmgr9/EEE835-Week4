int pin = A0; //initialize of the pin A0

void setup() {
  Serial.begin(9600);//start serial communication
  while(!Serial);//wait until serial monitor gets ready
}

void loop() {
  uint16_t rawADC = analogRead(pin);  // Read the raw analog value (0–1023) from the specified analog input pin
  float voltage = 3.3*rawADC/1023.0;  // Convert the raw ADC value to voltage (assuming a 3.3V reference)

   // Print the raw ADC value to the Serial Monitor
  Serial.print("ADC Value = "); 
  Serial.print(rawADC);
  Serial.println(".");

   // Print the voltage value to the Serial Monitor
  Serial.print("Voltage = ");
  Serial.println(voltage);
  Serial.println(" V.");

  //Wait 1 sec before repeating the loop
  delay(1000);
}
