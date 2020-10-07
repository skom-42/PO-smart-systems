#define LEDR_PIN 9
#define LEDG_PIN 10
#define LEDB_PIN 11

String message;
void setup() {
  // put your setup code here, to run once:
pinMode(LEDR_PIN, OUTPUT);
pinMode(LEDG_PIN, OUTPUT);
pinMode(LEDB_PIN, OUTPUT);
Serial.begin(9600);
}

void loop() {
while(Serial.available()){
  char incomingChar = Serial.read();
  if(incomingChar >= '0' && incomingChar <= '9'){
    message += incomingChar;
    }
    else if (incomingChar == '\n'){
      
      String R = getValue(message, ',',0);
      String G = getValue(message, ',',1);
      String B = getValue(message, ',',2);
      setColor(R.toInt(),G.toInt(),B.toInt());
      message = "";
      }
      else {
        message += incomingChar;
        }
        
  }
}

void setColor(int red, int green, int blue)

{

#ifdef COMMON_ANODE

red = 255 - red;

green = 255 - green;

blue = 255 - blue;

#endif

analogWrite(LEDR_PIN, red);

analogWrite(LEDG_PIN, green);

analogWrite(LEDB_PIN, blue);

}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
