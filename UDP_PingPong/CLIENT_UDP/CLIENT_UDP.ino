/*
  @author: acbernardez
  Date: 07-02-2021

  Abstract:
    This file (CLIENT ESP8266) is part of a simple example of a PING-PONG 
    through UDP datagrams/packets between an ESP8266 module and a RaspberryPi4.

  NOTE: INPUTPORT and OUTPUTPORT is asigned to 9999, this way ESP8266 and RbPi will
    know exactly where They have to send or receive packets.
*/

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "TP-Link_34E8";
const char* password = "71028309";

WiFiUDP udpConn; //UDP-CONNECTION var
unsigned int localUdpPort = 9999; //INPUT PORT 
char inputDatagram[255]; //BUFFER SIZE FOR INPUT DATAGRAMS
char outputDatagram[] = "ESP8266: PING"; //OUTPUT MESSAGE


/**
 * Function: setup
 * It will connect ESP8266 - WLAN 802.11n
 * And an UDP_Connection will be created
 * 
*/
void setup()
{
  Serial.begin(115200); //Monitor Serial at 115200 B
  Serial.println();

  //Trying to connect to Wlan
  WiFi.begin(ssid, password);

  Serial.printf("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  
  //Starting UDP_Connection at @var:localUdpPort
  udpConn.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);

}

/**
 * Function: loop()
 * It will receive packets and It will send a reply when inputpacket is received.
*/

void loop() 
{
  //Parsing INPUT packet
  int packetSize = udpConn.parsePacket();
  
  if (packetSize){
      // receive incoming UDP packets
      Serial.printf("Received %d bytes from %s, port %d\n", packetSize, udpConn.remoteIP().toString().c_str(), udpConn.remotePort());
      int len = udpConn.read(inputDatagram, 255);
      
      if (len > 0){
          inputDatagram[len] = 0;
      }
      Serial.printf("UDP packet contents: %s\n", inputDatagram);
  
      //UDP Reply
      udpConn.beginPacket(udpConn.remoteIP(), udpConn.remotePort());
      udpConn.write(outputDatagram);
      udpConn.endPacket();
  }  
}
