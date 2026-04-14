#include <Wire.h>

const byte deviceAddress = 0x08;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(deviceAddress);
  Wire.write(0x01);
  Wire.endTransmission();

  Wire.requestFrom(deviceAddress, (byte)2);
  while (Wire.available()) {
    byte data = Wire.read();
    Serial.print("I2C Data: ");
    Serial.println(data);
  }

  delay(500);
}
