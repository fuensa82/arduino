const int Led13 = 13;
const int bajaToldo=9;
const int paraToldo=11;
const int subeToldo=10;

void setup()
{
  Serial.begin(9600);
  pinMode(Led13, OUTPUT);
  pinMode(bajaToldo,OUTPUT);
  pinMode(paraToldo,OUTPUT);
  pinMode(subeToldo,OUTPUT);
}
 
void loop()
{
  if (Serial.available()>0){
    //leemos la opcion enviada
    String data = Serial.readStringUntil('\n');
    Serial.print("Datos Leidos: ");
    Serial.println(data);
    digitalWrite(Led13,HIGH);
    if(data=="sube"){
      digitalWrite(subeToldo,HIGH);
      delay(50);
      digitalWrite(subeToldo,LOW);
    }else if(data=="para"){
      digitalWrite(paraToldo,HIGH);
      delay(50);
      digitalWrite(paraToldo,LOW);
    }else if(data=="baja"){
      digitalWrite(bajaToldo,HIGH);
      delay(50);
      digitalWrite(bajaToldo,LOW);
    }
    digitalWrite(Led13,LOW);
  }
}
