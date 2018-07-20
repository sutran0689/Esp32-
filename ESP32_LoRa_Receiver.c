#include <Wire.h> 
#include "SSD1306.h"
 
#include <SPI.h>
#include <LoRa.h>

SSD1306 display (0x3c, 4, 15);

#define SS 18
#define RST 14
#define DIO 26

#define BAND 443E6
#define spreadingFactor 9
#define signalBandwidth  31.25E3 
#define codingRateDenominator 8

void setup (){
    pinMode (16, OUTPUT);
    digitalWrite (16, LOW);
    delay(50);
    digitalWrite (16, HIGH);
    delay(50);

    display.init ();
    display.flipScreenVertically ();
    display.setFont (ArialMT_Plain_10);
    display.setTextAlignment (TEXT_ALIGN_LEFT);

    Serial.begin (115200);
    while (!Serial) ;
    delay(1000);

    Serial.println ("LoRa Receiver");
    display.drawString (5, 5, "LoRa Receiver");
    display.display ();

    SPI.begin (5, 19, 27, 18);
    LoRa.setPins (SS, RST, DIO);

    if (!LoRa.begin (BAND)) {
        display.drawString (5, 25, "Starting LoRa failed!");
        while(1);
    }
    Serial.println("LoRa Initial OK!");

    LoRa.setSpreadingFactor(spreadingFactor);
    LoRa.setSignalBandwidth (signalBandwidth);
    LoRa.setCodingRate4(codingRateDenominator);

    display.drawString (5, 25, "LoRa Initializing OK!");
    display.display ();
}

void loop()  {
    int packetSize = LoRa.parsePacket() ;  // tra ve kich thuoc goi theo byte = 0 neu trua nhan
    if (packetSize)  {
        Serial.print ("Received packet. ");

        display.clear ();
        display.setFont (ArialMT_Plain_16);
        display.drawString (3, 0, "REceived packet ");
        display.display ();

        // read packet
        //Returns number of bytes available for reading.
        while (LoRa.available())  {
            String data = LoRa.readString ();
            Serial.print (data);
            display.drawString (20, 22, data);
            display.display ();
        }

        Serial.print (" with RSSI ");
        Serial.println (LoRa.packetRssi ());
        Serial.println ("with RSSI ");
        Serial.println(LoRa.packetSnr());
        display.drawString (0, 45, (String)LoRa.packetRssi() + "dB (" + (String)LoRa.packetSnr () + "dB)");
        display.display();
        
    }

}