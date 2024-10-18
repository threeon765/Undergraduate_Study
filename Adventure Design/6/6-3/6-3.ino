int RGB[] = {3, 5, 6};
 
void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(RGB[i], OUTPUT);
  }
}

void loop()
{
  digitalWrite(RGB[1], HIGH);
  digitalWrite(RGB[2], HIGH);
  for (int i = 255; i >= 0; i--) {
    analogWrite(RGB[0], i);
    delay(10);
  }
  digitalWrite(RGB[0], HIGH);
  digitalWrite(RGB[2], HIGH);
  for (int i = 255; i >= 0; i--) {
    analogWrite(RGB[1], i);
    delay(10);
  }
  digitalWrite(RGB[1], HIGH);
  digitalWrite(RGB[0], HIGH);
  for (int i = 255; i >= 0; i--) {
    analogWrite(RGB[2], i);
    delay(10);
  }
}