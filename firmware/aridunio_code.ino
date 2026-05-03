define MIC_PIN A0

void setup() {
  Serial.begin(115200);
  pinMode(MIC_PIN, INPUT);
  // Edge Impulse data forwarder header
  Serial.println("Channels: value");
  Serial.println("Frequency: 8000");
  Serial.println("---");
}

void loop() {
  int raw = analogRead(MIC_PIN);
  int value = raw - 512;
  Serial.println(value);
  delayMicroseconds(125);
}
