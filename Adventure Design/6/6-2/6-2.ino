int vr = A0;
int LED[] = {9, 10, 11};
 
void setup() {
  Serial.begin(9600);
  pinMode(vr, INPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
}

void loop()
{
  int adc = analogRead(vr);
  int count_led;
  if (adc < 1024/3) {
    count_led = 1;
  }
  else if (adc < 1024*2/3) {
    count_led = 2;
  }
  else {
    count_led = 3;
  }
  for (int i = 0; i < 3; i++) {
    if (i < count_led) {
      digitalWrite(LED[i], HIGH);
    }
    else {
      digitalWrite(LED[i], LOW);
    }
  }
  Serial.println(String("ADC : ") + adc + ", LED count : " + count_led);
  delay(1000);
}