const int led13 = 13;
const int bajaToldo=9;
const int paraToldo=11;
const int subeToldo=10;

void setup()
{
  Serial.begin(9600);
  pinMode(led13, OUTPUT);
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
    //digitalWrite(led13,HIGH);
    if(data=="quitaToldo"){
      digitalWrite(subeToldo,HIGH);
      Serial.println("quitaToldo");
      digitalWrite(led13,LOW);
      delay(50);
      digitalWrite(subeToldo,LOW);
    }else if(data=="paraToldo"){
      digitalWrite(paraToldo,HIGH);
      Serial.println("paraToldo");
      delay(50);
      digitalWrite(paraToldo,LOW);
      delay(200);
      digitalWrite(led13,LOW);
      delay(200);
      digitalWrite(led13,HIGH);
      delay(200);      
      digitalWrite(led13,LOW);
      delay(200);
      digitalWrite(led13,HIGH);
      delay(200);
      digitalWrite(led13,LOW);
      delay(200);
      digitalWrite(led13,HIGH);
      delay(200);
      digitalWrite(led13,LOW);
      
      
    }else if(data=="ponToldo"){
      digitalWrite(bajaToldo,HIGH);
      Serial.println("Bajando");
      digitalWrite(led13,HIGH);
      delay(50);
      digitalWrite(bajaToldo,LOW);
    }
    //digitalWrite(Led13,LOW);
  }
}
