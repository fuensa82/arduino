const int led13 = 13;
const int bajaToldo=9;
const int paraToldo=11;
const int subeToldo=10;
String estadoToldo="off";

void setup()
{
  Serial.begin(9600);
  pinMode(led13, OUTPUT);
  pinMode(bajaToldo,OUTPUT);
  pinMode(paraToldo,OUTPUT);
  pinMode(subeToldo,OUTPUT);
  //Quitamos el toldo al empezar para que el estado sea off
  digitalWrite(led13,LOW);
  delay(50);
  digitalWrite(subeToldo,LOW);
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
      estadoToldo="off";
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
      estadoToldo="half";
    }else if(data=="ponToldo"){
      digitalWrite(bajaToldo,HIGH);
      Serial.println("Bajando");
      digitalWrite(led13,HIGH);
      delay(50);
      digitalWrite(bajaToldo,LOW);
      estadoToldo="on";
    }else if(data=="estadoToldo"){
      digitalWrite(bajaToldo,HIGH);
      Serial.println(estadoToldo);
    }
    //digitalWrite(Led13,LOW);
  }
}