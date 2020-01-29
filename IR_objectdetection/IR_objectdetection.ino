int IR1=14;
int IR2=12; 
int led1=2;
int led2=5;
int relay=15;
int buzzer =4;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(IR1, INPUT);
pinMode(IR2, INPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(relay, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val1 = digitalRead(IR1);
int val2 = digitalRead(IR2);
if (val1 == HIGH)
{
  digitalWrite(buzzer,HIGH);
  digitalWrite(led1,HIGH);
  digitalWrite(relay,HIGH);
  Serial.println("Object1 is detected");
  }

else if (val2 == HIGH)
{
  digitalWrite(buzzer,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(relay,HIGH);
  Serial.println("Object2 is detected");
  }/
else
{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(buzzer,LOW);
  digitalWrite(relay,LOW);
  }
delay(1000);
}
