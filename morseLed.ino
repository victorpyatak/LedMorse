int led = 8;

void setup(){
  Serial.begin(9600);
  pinMode(led , OUTPUT);
 // digitalWrite(led , HIGH);
  Serial.print("Decode : ");
}

void dot(){
  digitalWrite(led , HIGH);
  delay(300);
  digitalWrite(led , LOW);
  delay(300);
}

void dash(){
  digitalWrite(led ,HIGH);
  delay(600);
  digitalWrite(led , LOW);
  delay(300);
}

void LetterSpace(){
  delay(300);
}
void WordSpace(){
  delay(600);
}


char alpha[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
String morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };


String toMorse(String , String[]);
String toMorse(String text , String morse[]){
  String morseValue ;
  String letterSpace = "  ";
  String wordSpace = "   ";
  for(int k = 0; k < text.length() ; k++){
    if(text[k] != ' '){
      text[k] = toupper(text[k]);
      letterSpace += morse[text[k] - 'A'] + " ";
      morseValue = letterSpace;
      }
    if(text[k] == ' '){
        WordSpace();
    }
  }
  return morseValue ;
}


char readStr = 0;
String text , morsecode;
char temp;

void loop(){
  if(Serial.available() > 0){
    readStr = Serial.read();

    if(readStr != '\n'){
      text += readStr;
    }else{
      Serial.println(text);
      Serial.print("Here will go Morse code:");
      morsecode = toMorse(text , morse);
      Serial.print(morsecode);
      Serial.println(morsecode.length()-3);
      for(int i = 0; i < morsecode.length()-1; i ++){
        temp = morsecode[i];
        if(temp == '.'){
          dot();
        }
        if(temp == '-'){
          dash();
        }
        
       // temp = "";
      }

        LetterSpace();
        Serial.println();
        text = "";
        Serial.print("Decode : ");

      }
    }
  
}
