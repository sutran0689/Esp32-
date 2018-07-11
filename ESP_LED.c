int led = 14;
void setup() 
{
    Serial.begin(115200);
    pinMode(led, OUTPUT);
}
void loop()
{
    digitalWrite(led, HIGH);
    Serial.println("sang");
    delay(1000);
    digitalWrite(led, LOW);
    Serial.println("tat");
    delay(1000);
}