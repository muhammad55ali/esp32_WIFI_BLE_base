

/*
esp is the server
Laptop/PC is client 

we can turn digital pins state through udp message from client


requirments
 - same access point
 - port number and IP of SERVER


*/

#include <WiFi.h>
#include <WiFiUdp.h>
const char*  ssid = "Infinix S5";
const char*  password = "55555555";
const char*  udpAddress = "192.168.43.255";
unsigned int localPort_ = 9999;
WiFiUDP udp;
IPAddress ipServer(192, 168, 43, 225); 
IPAddress ipClient(192, 168, 43, 13);
IPAddress Subnet(255, 255, 255, 0);
char packetBuffer[255];

void setup()
{ 
  Serial.begin(115200);
  wifi_def();
 
}

void Udp_Packet_Check(){

  // If we recieve any packet
  if(udp.parsePacket() ){  
    
    udp.read(packetBuffer, 255);
    
    //char * strtokIndx;
   // strtokIndx = strtok(packetBuffer,",");
    //kp = atof(strtokIndx); 
    //strtokIndx = strtok(NULL, ",");
    //ki = atof(strtokIndx);
    //strtokIndx = strtok(NULL, ",");
   // kd= atof(strtokIndx);
    Serial.println("\n\n\nGET Ready !!");

   
  
  }
}

void loop()
{
  Udp_Packet_Check();
  
  }

void wifi_def(){
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
