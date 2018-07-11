
#include <Arduino.h>
#include <U8x8lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
// khai bao chan cho cam bien khoang cach HCSR04
#define trigPin 13
#define echoPin 12

U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);

void setup(void)
{
  // Setup cho HCSR04
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  u8x8.begin();
  //u8x8.setFlipMode(1);
}
void pre(void)
{
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);    
  u8x8.clear();
  u8x8.inverse();
  u8x8.setCursor(4,0);
  u8x8.print("SuTran");
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f); 
  u8x8.noInverse();
  u8x8.setCursor(0,1);
}


void loop(void)
{
  pre();
  u8x8.print("KHOANG CACH:");
  u8x8.setCursor(11,1);

  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 
  Serial.print(distance);
  Serial.println(" cm");

  u8x8.print(i);
  delay(500);

}
