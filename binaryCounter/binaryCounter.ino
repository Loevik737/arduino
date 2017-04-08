
int led[] = {2,3,4,5,6,7,8,9}; 
int ledNum = sizeof(led) - 1;
int button = 13;
int buttonState = 0;
int isPushed = 0;
int counter = 0;
void setup() {   
  for (int i = 0; i < ledNum; i++){
    pinMode(led[i], OUTPUT);
  }
  pinMode(button, INPUT);
}

void loop() {
  delay(100);
  buttonState = digitalRead(button);
   if (buttonState == HIGH && !isPushed) {
     isPushed = 1;
     counter += 1;
  } 
   if(buttonState == LOW){
     isPushed = 0;
   }
   String bin = String(counter,BIN);
   int zeros = bin.length();
   for (int i=0; i < 8 - zeros; i++) {
    bin = "0" + bin;
    }
   for(int i = 0; i < ledNum; i++){
       if(bin[7-i] == '1'){
          digitalWrite(led[i], HIGH);
       }    
       else{
         digitalWrite(led[i], LOW);
       }
   }
  
}
