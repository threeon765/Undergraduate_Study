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
  if (digitalRead(button0) == HIGH) {
    digitalWrite(led0, HIGH);
  }
  else digitalWrite(led0, LOW);
  if (digitalRead(button1) == HIGH) {
    digitalWrite(led1, HIGH);
  }
  else digitalWrite(led1, LOW);
  if (digitalRead(button2) == HIGH) {
    digitalWrite(led2, HIGH);
  }
  else digitalWrite(led2, LOW);
  if (digitalRead(button3) == HIGH) {
    digitalWrite(led3, HIGH);
  }
  else digitalWrite(led3, LOW);
}
