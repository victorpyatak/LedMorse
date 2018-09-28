int led = 8;

void setup(){
  Serial.begin(9600);
  pinMode(led ,OUTPUT);
}
void dot(){
  digitalWrite(led , HIGH);
  delay(200);
  digitalWrite(led , LOW);
  //delay(200);
}

void dash(){
  digitalWrite(led ,HIGH);
  delay(600);
  digitalWrite(led , LOW);
 // delay(200);
}

void LetterSpace(){
  delay(200);
}
void WordSpace(){
  delay(600);
}

void loop(){
  dash();
  LetterSpace();
  dot();
  LetterSpace();
  dot();
  LetterSpace();
  dot();
  LetterSpace();
  dash();
  LetterSpace();
}
