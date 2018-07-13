const int Led13=13;
void setup()
{
	Serial.begin(9600);
    pinMode(Led13,OUTPUT);
}

void loop()
{
	if(Serial.available()>0){
        String data=Serial.readStringUntil('\n');
        Serial.print("Datos desde VSC: ");
        Serial.println(data);
        if(data=="on"){
            digitalWrite(Led13,HIGH);
        }else if(data=="off"){
            digitalWrite(Led13,LOW);
        }
    }
}
