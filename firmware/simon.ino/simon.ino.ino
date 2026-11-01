int button[4] = {2, 4, 6, 12};
int led[4]    = {3, 5, 7, 13};
int centreLed = 10;
int modeSwitch = 14;
int buzzer = 15;

int notes[4] = {262, 330, 392, 523};
int winLength = 8;

int sequence[8];
int length = 0;


void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 4; i++) {
    pinMode(button[i], INPUT_PULLUP);
    pinMode(led[i], OUTPUT);
  }

  pinMode(centreLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(modeSwitch, INPUT_PULLUP);

  randomSeed(micros());
}


void lightled(int p) {
  digitalWrite(led[p], HIGH);
  tone(buzzer, notes[p]);
  delay(400);
  digitalWrite(led[p], LOW);
  noTone(buzzer);
  delay(150);
}


int waitForButton() {
  while (true) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(button[i]) == LOW) {
        digitalWrite(led[i], HIGH);
        tone(buzzer, notes[i]);

        while (digitalRead(button[i]) == LOW) {
          delay(10);
        }
        digitalWrite(led[i], LOW);
        noTone(buzzer);
        delay(50);
        return i;
      }
    }
  }
}


void winAnimation() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(led[i], HIGH);
    tone(buzzer, notes[i]);
    delay(250);
  }
  digitalWrite(centreLed, HIGH);
  tone(buzzer, 784);
  delay(800);
  noTone(buzzer);
  for (int i = 0; i < 4; i++) {
    digitalWrite(led[i], LOW);
  }
  digitalWrite(centreLed, LOW);
}


void loseAnimation() {
  for (int k = 0; k < 3; k++) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(led[i], HIGH);
    }
    digitalWrite(centreLed, HIGH);
    tone(buzzer, 150);
    delay(200);

    for (int i = 0; i < 4; i++) {
      digitalWrite(led[i], LOW);
    }
    digitalWrite(centreLed, LOW);
    noTone(buzzer);
    delay(150);
  }
}


void loop() {
  Serial.println("Press any button to start");
  waitForButton();

  length = 0;
  boolean gameOver = false;

  boolean reverse = (digitalRead(modeSwitch) == LOW);

  if (reverse) {
    Serial.println("MODE : REVERSE");
  }
  else {
    Serial.println("MODE : NORMAL");
  }

  while (length < winLength && gameOver == false) {
    sequence[length] = random(0, 4);
    length = length + 1;
    Serial.print("Round ");
    Serial.println(length);

    delay(500);
    for (int i = 0; i < length; i++) {
      lightled(sequence[i]);
    }

    if (reverse) {
      digitalWrite(centreLed, HIGH);
    }

    for (int i = 0; i < length && gameOver == false; i++) {
      int correct;
      if (reverse) {
        correct = sequence[length - 1 - i];
      }
      else {
        correct = sequence[i];
      }

      int pressed = waitForButton();
      if (pressed != correct) {
        gameOver = true;
      }
    }

    digitalWrite(centreLed, LOW);
  }

  if (gameOver) {
    Serial.println("GAME OVER");
    loseAnimation();
  }
  else {
    Serial.println("GOAT");
    winAnimation();
  }
  delay(800);
}