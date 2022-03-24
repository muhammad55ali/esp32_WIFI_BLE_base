

/*
Esp32 is the server
Laptop is client 
we are sending udp message(Hello, WOrld!) from client and receiving by this  esp server code
requirments
 - same access point
 - port number.
*/
#include <WiFi.h>
#include <WiFiUdp.h>
const char*  ssid = "Luqman IT";
const char*  password = "222333444";
unsigned int localPort_ = 3333;
WiFiUDP udp;
char packetBuffer[255];
void setup()
{ 
  Serial.begin(115200);
  wifi_connect();
}
void Udp_Packet_Check(){
  if(udp.parsePacket() ){  
    udp.read(packetBuffer, 255);
    Serial.println("\nReceived message is:");
    Serial.println(packetBuffer);  
  }
}
void loop()
{
  Udp_Packet_Check();
  }
void wifi_connect(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {                             // Exit only when connected
    delay(500);
  Serial.print(".");}
  Serial.print("\nConnected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  delay(3000);
  udp.begin(localPort_);                                              // Begin the udp communication
}
