from socket import *

import time
from itertools import count
from multiprocessing import Process

serverName="127.0.0.1"
serverPort = 2500

counter = count(0)

def sentUDP(x):
    message = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    time_string = time.asctime()
   
    print("Count : ",x)
    print("I send message to 127.0.0.1:2500")
    print("เวลาที่ส่ง"+time_string)
    print("It says => ",message)

    clientSocket = socket(AF_INET, SOCK_DGRAM)
    clientSocket.sendto(message.encode('utf-8'),(serverName, serverPort)) 
    response = clientSocket.recvfrom(2048) 
    print (response)
    clientSocket.close()

    print(" ")

def runUDP():
    time.sleep(1)
    for x in range(0, 3):
        sentUDP(x)
        next(counter)

p1 = Process(target=runUDP, name='Process_inc_forever')

if __name__ == '__main__':

    p1.start()
    p1.join(timeout=5)
    if p1.exitcode is None:
        print(f'Oops, {p1} timeouts!')
        p1.terminate()
 
