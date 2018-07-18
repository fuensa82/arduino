
const int led13=13;

void setup()
{
	Serial.begin(9600);
    pinMode(led13,OUTPUT);
}

void loop(){
	if(Serial.available()>0){
        String data=Serial.readStringUntil('\n');
        Serial.print("Datos desde VSC: ");
        Serial.println(data);
        if(data=="on"){
            digitalWrite(led13,HIGH);
        }else if(data=="off"){
            digitalWrite(led13,LOW);
        }
    }
}
