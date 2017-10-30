int switchState = 0;
int state_1 = 0;
int state_2 = 0;
int state_3 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

  state_1 = HIGH;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(2) == HIGH) {
    switchState = not switchState;
    delay(250);
  }
//  digitalWrite(3, switchState);
  if (switchState == LOW) {
    if (state_1 == HIGH) {
      state_2 = HIGH;
      state_1 = LOW;
    } else if (state_2 == HIGH) {
      state_2 = LOW;
      state_3 = HIGH;
    } else if (state_3 == HIGH) {
      state_3 = LOW;
      state_1 = HIGH;
    }
  }
  digitalWrite(3, state_1);
  digitalWrite(4, state_2);
  digitalWrite(5, state_3);
  delay(250);
}
