
#define LED_PIN 9
#define POT_PIN A0
////
void setup(){

  pinMode(LED_PIN,OUTPUT);
  pinMode(POT_PIN,INPUT);
 
}

void loop(){
 int r,b;
r = analogRead(POT_PIN);
 b = r/4;
  analogWrite(LED_PIN,b);
  delay(r);
  digitalWrite(LED_PIN,LOW);
  delay(r);
}
//
// delay(900);
// digitalWrite(LED_PIN,LOW);
