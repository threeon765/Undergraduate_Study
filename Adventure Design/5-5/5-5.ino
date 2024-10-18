int pins[] = {2,3,4,5};
int state = -1;

void setup() {
  Serial.begin(9600);
  for (int i = 0 ; i < 4 ; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    Serial.println(String("You entered \'") + data + '\'');
    if (data >= '1' && data <= '4') {
      state = data - '0' - 1;
      Serial.print("LED ");
      Serial.print(state + 1);
      Serial.println(" is ON...");
    }
    else if (data == '5') {
      state = -1;
      Serial.print("LED Repetition Let's GOOOOOO ");
    }
  }
  else {
    Serial.println("* Invlaid LED number...");
  }
  if (state != -1) {
    for (int i = 0; i < 4; i++) {
      if (i == state) {
        Serial.print("O ");
        digitalWrite(pins[i], HIGH);
      }
      else {
        Serial.print("X ");
        digitalWrite(pins[i], LOW);
      }
    }
  }
  else if (state == -1) {
    for (int i = 0; i < 4; i++) {
      Serial.print("O ");
    }
    for (int t = 0; t < 100; t++) {
      for (int i = 0; i < 4; i++) {
        digitalWrite(pins[i], HIGH);
        delay(1000. / pow(2,t));
        digitalWrite(pins[i], LOW);
      }
    }  
  }
  Serial.println();
}
