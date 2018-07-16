
byte ledPin = 14; //khai bao chan nut nhan
byte interruptPin = 12;   // chan nut nhan su dung ngat
volatile byte state = LOW; 
////////////////////////////////////////////////////////
void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
    /* attachinterrupt(,,) to the pin ham blink se duoc goi khi co su thay doi tren chan interruptPin*/

}
///////////////////////////////////////////////////////////////
void blink()
{
    state = !state;
    digitalWrite(ledPin , state);
}
///////////////////////////////////////////////////////////////
void loop()
{

}
