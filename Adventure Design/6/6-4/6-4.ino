int LED[] = {9, 10, 11};
 
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(LED[i], OUTPUT);
  }
  pinMode(A0, INPUT);
}

void loop() {
  int adc = analogRead(A0);
  int pwm[3] = {0, };
  Serial.println(String("ADC value : ") + adc);
  for (int i = 2; i >= 0; i--) {
    if (adc >= 341 * i) {
      pwm[i] = adc - 341 * i;
      adc -= (pwm[i] + 1);
    }
    analogWrite(LED[i], pwm[i]);
    Serial.print(" ");
    Serial.print(pwm[i]);
  }
  Serial.println();
  delay(500);
}