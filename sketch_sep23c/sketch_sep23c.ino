#include <math.h>
int minute = 1;


void setup() 
{
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

int tempCount(double i){
  double k;
if(i = i+0.1){
  k = k+10;
}
  return k;
}

void loop() {
  float v = analogRead(A0) *0.5 / 1024.0;
  float temperature = -14.46 * log((10000 * v) / (5 - v) / 27074);
  
  Serial.println (temperature);
  Serial.println(v);
  Serial.println (minute);

  digitalWrite(9,tempCount(temperature));

  delay(600);
  ++minute;
}
