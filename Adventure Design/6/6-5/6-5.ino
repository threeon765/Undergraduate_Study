int LED[] = {9, 10, 11};
int RGB[] = {3, 5, 6};
 
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(LED[i], OUTPUT);
    pinMode(RGB[i], OUTPUT);
  }
  pinMode(A0, INPUT);
}

void loop() {
  int adc = analogRead(A0);
  int originaladc = adc;
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
  if (originaladc < 1024/3) {
    Serial.print(" case1"); 
    analogWrite(RGB[0], 150);   
    analogWrite(RGB[1], 255); 
    analogWrite(RGB[2], 255); 
  }
  else if (originaladc >= 1024/3 && originaladc < 1024*2/3) {
    Serial.print(" case2");
    analogWrite(RGB[0], 255);   
    analogWrite(RGB[1], 150); 
    analogWrite(RGB[2], 255);    
  }
  else {
    Serial.print(" case3");
    analogWrite(RGB[0], 255);   
    analogWrite(RGB[1], 255); 
    analogWrite(RGB[2], 150); 
  }
  Serial.println();
  delay(500);
}