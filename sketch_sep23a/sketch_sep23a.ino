int LEDrot = 12;
int LEDgelb =11;
int LEDgruen =10;


int state = 1;

void setup() 
{
  
  pinMode(LEDrot,OUTPUT);
  pinMode(LEDgelb,OUTPUT);
  pinMode(LEDgruen,OUTPUT);

}

void loop() {
  
    Statemashine();


  delay(1000);

}

void Statemashine(void){
  switch(state)
  {
    case 1:
    digitalWrite(LEDrot, HIGH);
    digitalWrite(LEDgelb, LOW);
    digitalWrite(LEDgruen, LOW);
    state++;
    break;

        case 2:
    digitalWrite(LEDrot, HIGH);
    digitalWrite(LEDgelb, HIGH);
    digitalWrite(LEDgruen, LOW);
    state++;
    break;


    case 3:
    digitalWrite(LEDrot, LOW);
    digitalWrite(LEDgelb, LOW);
    digitalWrite(LEDgruen, HIGH);
    state++;
    break;


    case 4:
    digitalWrite(LEDrot, LOW);
    digitalWrite(LEDgelb, HIGH);
    digitalWrite(LEDgruen, LOW);
    state = 1;
    break;

  }
}
