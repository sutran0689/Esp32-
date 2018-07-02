#include <Arduino.h>
#include <U8x8lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);

void setup(void)
{
  u8x8.begin();
  //u8x8.setFlipMode(1);
}
// setup ban dau cho oled
void pre(void)
{
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);    //set keu ru lieu 'f','u','r','n'
  u8x8.clear();
  u8x8.inverse();           // sang nen chu
  u8x8.setCursor(4,0);      // cho toi vi tri bst dau ky tu
  u8x8.print("SuTran");
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f); 
  u8x8.noInverse();
  u8x8.setCursor(0,1);
}
void loop(void)
{
  int i;
  uint8_t c, r, d;
  pre();
  u8x8.print("Hello");
  u8x8.setCursor(0,2);
  u8x8.print("My name is su");
  u8x8.setCursor(0,3);
  u8x8.print("I'm 29 years old");
  u8x8.setCursor(0,4);
  u8x8.print("I'm from VN");
  u8x8.setCursor(0,5);
  u8x8.print("Nice to meet you"); 
  u8x8.setCursor(0,6); 
  u8x8.print((int)u8x8.getCols());
  u8x8.print("x");
  u8x8.print((int)u8x8.getRows());
 
  //delay(2000);
  while(1);
}