void setup(){
  Serial.begin(9600);
  Serial.print("Decode : ");
}


char alpha[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
String morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };


String toMorse(String , String[]);
String toMorse(String text , String morse[]){
  String morseValue ;
  String letterSpace = "  ";
  String wordSpace = "   ";
  for(int k = 0; text[k] ; k++){
    if(text[k] != ' '){
      text[k] = toupper(text[k]);
      letterSpace += morse[text[k] - 'A'] + " ";
      morseValue = letterSpace;
      }
    if(text[k] == ' '){
      letterSpace += wordSpace;
    }
  }
  return morseValue ;
}


char readStr = 0;
String text , morsecode;


void loop(){
  if(Serial.available() > 0){
    readStr = Serial.read();

    if(readStr != '\n'){
      text += readStr;
    }else{
      Serial.println(text);
      Serial.print("Here will go Morse code : ");
      Serial.println(toMorse(text , morse));
      text = "";
      Serial.print("Decode : ");

    }
  }
  
}
