int led0 = 4;
int led1 = 5;
int led2 = 6;
int led3 = 7;
int button0 = 8;
int button1 = 9;
int button2 = 10;
int button3 = 11;

void setup() {
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button0, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
}

void loop() {
  for (int i = 0; i < 100; i++) {
      float t = 1000. / (2 * pow(2,i));
      digitalWrite(led0, HIGH);
      delay(t);
      digitalWrite(led0, LOW);
      delay(t);
  }
  for (int i = 0; i < 100; i++) {
      float t = 1000. / (2 * pow(2,i));
      digitalWrite(led1, HIGH);
      delay(t);
      digitalWrite(led1, LOW);
      delay(t);
  }
  for (int i = 0; i < 100; i++) {
      float t = 1000. / (2 * pow(2,i));
      digitalWrite(led2, HIGH);
      delay(t);
      digitalWrite(led2, LOW);
      delay(t);
  }
  for (int i = 0; i < 100; i++) {
      float t = 1000. / (2 * pow(2,i));
      digitalWrite(led3, HIGH);
      delay(t);
      digitalWrite(led3, LOW);
      delay(t);
  }
}
