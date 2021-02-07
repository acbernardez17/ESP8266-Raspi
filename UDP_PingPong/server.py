'''
@author: acbernardez
Date: 07-02-2021

Abstract:
    This file (CLIENT RaspberryPi) is part of a simple example of a PING-PONG 
    through UDP datagrams/packets between an ESP8266 module and a RaspberryPi4.

    1 - Server sends a Pong-Packet to client. Client will reply back.
    2 - After that, Server will be waiting infinitely expecting an 
        inputdatagram to be processed.
    2 - Once Server receives response datagram, It will print it and after 2 seconds
        Server will send other Pong_datagram. 
    
    NOTE: UDP_PORT is assigned to 9999 for OUTPUT and INPUT. Thus ESP8266 will know
          which PORT is the correct server PORT to send a PING.
'''

import socket
import time

UDP_TARGET_IP = "192.168.0.30" #ESP8266 IP
UDP_PORT = 9999 #ESP8266/RaspberryPi PORT
MESSAGE = b"Server: PONG"
 
print("UDP target IP: %s" % UDP_TARGET_IP)
print("UDP target port: %s" % UDP_PORT)
print("MESSAGE: %s" % MESSAGE)
 
sock = socket.socket( socket.AF_INET, socket.SOCK_DGRAM)

sock.bind(('', UDP_PORT)) # OUTPUT SERVER PORT  

sock.sendto(MESSAGE, (UDP_TARGET_IP, UDP_PORT)) #Sending an initial datagram to activate ESP8266

while (True):
    data, addr = sock.recvfrom(1024) #Parsing inputpacket (1024 Bytes of size)
    print("Received Message: %s" % data)
    time.sleep(2)
    sock.sendto(MESSAGE, (UDP_TARGET_IP, UDP_PORT)) # Replay back to ESP8266