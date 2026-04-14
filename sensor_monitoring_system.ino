const int sensorPin = A0;
const int ledPin = 9;
const int windowSize = 10;
const int threshold = 600;

int samples[windowSize];
int indexPos = 0;
long sum = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  for (int i = 0; i < windowSize; i++) {
    samples[i] = 0;
  }
}

int movingAverage(int newValue) {
  sum -= samples[indexPos];
  samples[indexPos] = newValue;
  sum += newValue;
  indexPos = (indexPos + 1) % windowSize;
  return sum / windowSize;
}

void loop() {
  int rawValue = analogRead(sensorPin);
  int filteredValue = movingAverage(rawValue);

  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print(" | Filtered: ");
  Serial.println(filteredValue);

  if (filteredValue > threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(100);
}
