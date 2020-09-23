void setup()
{
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);
}

void loop()
{
  if (digitalRead(3) == 1) {
    digitalWrite(5, HIGH);
    delay(2000); // Wait for 2000 millisecond(s)
    digitalWrite(5, LOW);
    delay(2000); // Wait for 2000 millisecond(s)
  } else {
    digitalWrite(5, LOW);
  }

  if (digitalRead(4) == 1) {
    digitalWrite(5, HIGH);
    delay(2000); // Wait for 2000 millisecond(s)
    digitalWrite(5, LOW);
    delay(6000); // Wait for 6000 millisecond(s)
  } else {
    digitalWrite(5, LOW);
  }

  if (digitalRead(2) == 1) {
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
  }
}