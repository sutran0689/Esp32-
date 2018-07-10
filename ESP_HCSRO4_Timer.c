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

/*1 giây = 1000 mili giây = 1000.000 micro giây = 1000.000.000 nano giây*/
/* create a hardware timer */
hw_timer_t * timer = NULL;

/* LED pin */
int led = 14;
/* LED state */
volatile byte state = LOW;
////////////////////////////////////
volatile long duration, distance, c;
void khoangcach(void)
  {
  //long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  u8x8.setCursor(6,1);
  u8x8.print("   ");
  Serial.print(distance);
  Serial.println(" cm");
  u8x8.setCursor(6,1);
  u8x8.print(distance);
  }

////////////////////////////////////
void IRAM_ATTR onTimer(){
  
}
/////////////////////////////////////
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
/////////////////////////////////////
void setup() {
  Serial.begin(115200);
////////////////////////////////////////
  // Setup cho HCSR04
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  u8x8.begin();
  //u8x8.setFlipMode(1);
  pinMode(led, OUTPUT);
/////////////////////////////////////

  /* Use 1st timer of 4 */
  /* 1 tick take 1/(80MHZ/80) = 1us so we set divider 80 and count up */
  timer = timerBegin(0, 80, true);

  /* Attach onTimer function to our timer */
  timerAttachInterrupt(timer, &onTimer, true);

  /* Set alarm to call onTimer function every second 1 tick is 1us
  => 1 second is 1000000us */
  /* Repeat the alarm (third parameter) */
  timerAlarmWrite(timer, 1000000, true);

  /* Start an alarm */
  timerAlarmEnable(timer);
  Serial.println("start timer");
}
void loop(void)
{
  pre();
  u8x8.print("CU LY:");
  khoangcach();
  u8x8.setCursor(9,1);
  u8x8.print("cm");
  while(1);
}

