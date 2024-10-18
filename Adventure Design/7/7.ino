int water = A0;
int ballsw1 = 5;
int ballsw2 = 6;
int led1 = 2;
int led2 = 3;
int led3 = 9;
int led4 = 10;
int led5 = 11;
int BallVal;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(ballsw1, INPUT_PULLUP);
  pinMode(ballsw2, INPUT_PULLUP);
}

void loop() {

/*
  if (digitalRead(ballsw1) == LOW) {
    digitalWrite(led4, HIGH);
  }
  else {
    digitalWrite(led4, LOW);
  }
  if (digitalRead(ballsw2) == LOW) {
    digitalWrite(led5, HIGH);
  }
  else {
    digitalWrite(led5, LOW);
  }
*/


  BallVal = analogRead(water);
  if (BallVal <= 250) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
  }
  if (BallVal <= 450) {
      if (digitalRead(ballsw1) == LOW) {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, LOW);        
      }
      else {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
      }
  }
  if (BallVal > 450) {
      if (digitalRead(ballsw1) == LOW) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);        
      }
      else {
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
      }

  }  


}