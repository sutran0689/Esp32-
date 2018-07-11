byte pin[] = {13, 12, 14, 27, 26, 25, 33, 32}; // khai bao chan
byte a[]   = {13, 32, 12, 33, 14, 25, 27, 26};
byte b[]   = {27, 26, 14, 25, 12, 33, 13, 32};
byte pinCount ; // bien dem so chan
void setup()
{
    Serial.begin(115200);
    pinCount = sizeof(pin); // kiem tra do dai cua chuoi
    Serial.println(pinCount);
    for(int i = 0; i < pinCount ; i++ )
    {
        pinMode(pin[i], OUTPUT); // cau hinh cac chan la OUTPUT
        digitalWrite(pin[i], LOW);  // Mac dinh cac den led se tat
    }
}
/////////////////////////////////////////////////////////////////
void sangdan()
{
    for(int i = 0 ; i < pinCount ; i++)
    {
        digitalWrite(pin[i], HIGH); 
         Serial.println(i);
        delay(500);
    }
}
/////////////////////////////////////////////////////////////////
void tatdan()
{
    for(int i = pinCount-1 ; i >=0 ; i--)
    {
        digitalWrite(pin[i], LOW); 
         Serial.println(i);
        delay(500);
    }
}
////////////////////////////////////////////////////////////////////
void sangtungoaivao()
{
    for(int i = 0 ; i < pinCount ; i++)
    { 
        
        digitalWrite(a[i], HIGH); 
         Serial.println(i);
        delay(500);
    }
}
/////////////////////////////////////////////////////////////////////
void tattutrongra()
{
    for(int i = 0 ; i < pinCount ; i++)
    { 
        
        digitalWrite(b[i], LOW); 
         Serial.println(i);
        delay(500);
    }
}
/////////////////////////////////////////////////////////////////////
void loop()
{
  sangdan();
  tatdan();
  sangtungoaivao();
  tattutrongra();
}