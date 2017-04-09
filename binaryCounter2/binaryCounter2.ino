
int led[] = {2,3,4,5,6,7,8,9}; 
int ledNum = sizeof(led);
int potentiometer = 0;
int counter = 0;
void setup() {   
  for (int i = 0; i < ledNum; i++){
    pinMode(led[i], OUTPUT);
  };
  //for some reason setting it to 9600 makes the two last leds light up 
  Serial.begin(9600);
}

void loop() {
  counter += 1;
  int tempCount = counter;
  
  delay(analogRead(potentiometer));
  
  if(tempCount > 256){counter = 0;};

  for(int i = ledNum; i > -1; i--){
    if((tempCount - pow(2,i) ) >= 0){
        tempCount -= pow(2,i);
        digitalWrite(led[i], HIGH);
    }
    else{
        digitalWrite(led[i], LOW);
    };
  }
}
