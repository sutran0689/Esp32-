// ket noi ESP32 Voi WiFi
#include <WiFi.h>  // duong dan toi file chua thu vien WiFi.h

const char* ssid = "YourNetworkName"; // khai bao bien toan cuc tro ten wifi
const char* password = "yourNetworkPass"; //khai bao mat khau Wifi cua ban

void setup()
{
   Serial.begin(115200); // khoi dong mot cong tren Serial voi mot toc do baudrate de giao tiep tren may tinh
  
   WiFi.begin(ssid, password); //khoi tao cai dat mang cua thu vien
   /*WiFi.status() la ham  khi duoc goi no tra lai trang thai ket noi 
     WL_CONNECTED : Khi duoc ket noi voi mang WiFi
     WL_DISCONNECTED : Khi khong ket noi duoc mang 
     ...*/
   while(WiFi.status() != WL_CONNECTED)
   {
       delay(500);
       Serial.println("connecting to WiFi network");
   }
   Serial.println("Connected to the WiFi network");
}
void loop()
{

}

