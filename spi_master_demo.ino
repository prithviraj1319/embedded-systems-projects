#include <SPI.h>

const int chipSelectPin = 10;

void setup() {
  pinMode(chipSelectPin, OUTPUT);
  digitalWrite(chipSelectPin, HIGH);
  SPI.begin();
  Serial.begin(9600);
}

void loop() {
  digitalWrite(chipSelectPin, LOW);
  byte response = SPI.transfer(0x55);
  digitalWrite(chipSelectPin, HIGH);

  Serial.print("SPI Response: ");
  Serial.println(response, HEX);
  delay(500);
}
