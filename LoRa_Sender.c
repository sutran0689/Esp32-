// tham khao ve oled
/* https://github.com/ThingPulse/esp8266-oled-ssd1306 */
// tham lhao LoRa
/*https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md#writing*/
#include <Wire.h>    // Thu vien nay cho phep ban giao tiep voi cac thiet bi I2C / TWI
#include <SSD13O6.h> // thu vien nay su dung cho Oled

#include <SPI.h>     // thu vien su dung cho chuon SPI su dung co LoRa
#include <LoRa.h>    // thu vien cho viec su dung chuc nang LoRa tren ESP32

#include <Arduino.h> // 
/**********************************************/
SSD1306 display(0x3c, 4, 15);   
//OLED pins to ESP32 GPIOs via this connecthin:
//OLED_SDA      GPIO4
//OLED_SCL      GPIO15
//OLED_RST      GPIO16     ? 0x3c

#define   SS  18
#define   RST 14
#define   DIO 26
//**********************************************/
// WIFI_LoRa_32 ports

// GPIO5     SX1278     SCK
// GPIO19    SX1278     MISO
// GPIO27    SX1278     MOSI
// GPIO18    SX1278     CS
// GPIO14    SX1278     RESET
// GPIO26    SX1278     IRQ(Interrupt Request)

#define BAND  434500000.00     // Chon tan so phu hop 
// #define BAND 429E6 //915E6

// #define BAND 434500000.00

#define spreadingFacter 9
#define SignalBandwidth 31.25E3
#define preambleLength 8
#define codingRateDenominator 8

int counter = 0;

void setup()
{
    pinMode(25, OUTPUT);   //GUI thanh cong led xe sang 1s

/*----------------------------------------------------------------*/
    pinMode(16, UOTPUT);
    digitalWrite(16, LOW);    // set GPIO16 low to reset OLED
    delay(50);
    digitalWrite(16, HIGH); 

    Serial.begin begin(115200);
    //while (!Serial);      // chuc nang nay can khi ban muon ket noi voi mayh tinh

    // khoi tao hien thi cho oled
    display.init();   // khoi tao man hinh
    display.flipScreenVertically();  // Turn the display upside down (xoay man hinh lon nguoc lai)
    display.setFont (ArialMT_Plain_16); // dat phong chu (ArialMT_Plain_10, ArialMT_Plain_16, ArialMT_Plain_24)
    // Specifies relative to which anchor point
    // the text is rendered. Available constants:
    // TEXT_ALIGN_LEFT, TEXT_ALIGN_CENTER, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER_BOTH
    display.setTextAlignment (TEXT_ALIGN_LEFT); 
    display.drawString (5, 5, "LoRa Sender");  // dinh vi toa do va hien thi van ban
    display.display();  // Write the buffer to the display memory
/*------------------------------------------------------------------*/

    SPI.begin (5, 19, 27, 18);   // KHAI bao chan cho spi
    LoRa.setPins (SS, RST, DIO);    //khai bao cac chan mac dinh duoc su dung boi thu vien
    Serial.println("LoRa Sender");     
    if (!LoRa.begin(BAND));         //Initialize the library with the specified frequency
    {
        Serial.println("Starting LoRa failed");
        while(1);
    }
    
    Serial.print ("LoRa Spreading Factor");
    Serial.println (spreadingFactor);
    LoRa.setSpreadingFactor (spreadingFactor);  // thay doi he so lan truyen cua song

    Serial.print("LoRa Signal Bandwidth");
    Serial.println(SignalBandwidth);
    LoRa.setSignalBandwidth(SignalBandwidth);   // thay doi bang thong tin hieu cua radio
    
    LoRa.setCodingRate4 (codingRateDenominator);   //Thay doi toc do ma hoa cua radio

    LoRa.setPreambleLength(preambleLength);   //Change the preamble length of the radio.

    Serial.pintln ("LoRa Initial OK ");
    display.drawString(5, 20, "LoRa Initializing Ok!");
    display.display ();
    delay(2000);
 /*----------------------------------------------------------------------*/
}


