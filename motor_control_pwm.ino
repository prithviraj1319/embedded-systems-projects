const int pwmPin = 5;
const int increaseButton = 2;
const int decreaseButton = 3;

int dutyCycle = 128;

void setup() {
  pinMode(pwmPin, OUTPUT);
  pinMode(increaseButton, INPUT_PULLUP);
  pinMode(decreaseButton, INPUT_PULLUP);
  Serial.begin(9600);
  analogWrite(pwmPin, dutyCycle);
}

void loop() {
  if (digitalRead(increaseButton) == LOW) {
    dutyCycle += 10;
    if (dutyCycle > 255) dutyCycle = 255;
    analogWrite(pwmPin, dutyCycle);
    Serial.print("Duty Cycle Increased: ");
    Serial.println(dutyCycle);
    delay(200);
  }

  if (digitalRead(decreaseButton) == LOW) {
    dutyCycle -= 10;
    if (dutyCycle < 0) dutyCycle = 0;
    analogWrite(pwmPin, dutyCycle);
    Serial.print("Duty Cycle Decreased: ");
    Serial.println(dutyCycle);
    delay(200);
  }
}
