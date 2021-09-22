from socket import *

import time
from itertools import count
from multiprocessing import Process

counter = count(0)
serverName = "127.0.0.1"
serverPort = 12000

def sentTCP(x):
    message = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    print("times : ",x)
    print("I send message to 127.0.0.1:2500")
    print("It says => ",message)

    try:
        clientSocket = socket(AF_INET, SOCK_STREAM)
        clientSocket.connect((serverName,serverPort)) 
        clientSocket.send(message.encode('utf-8'))
        modifiedSentence = clientSocket.recv(1024) 
        print ("From Server: ", modifiedSentence)
        clientSocket.close()
    except Exception as e: 
        print("error")
        print(e)
    print(" ")

def runTCP():
    time.sleep(1)
    for x in range(0, 3):
        sentTCP(x)
        next(counter)

p1 = Process(target=runTCP, name='Process_inc_forever')

if __name__ == '__main__':

    p1.start()
    p1.join(timeout=5)
    if p1.exitcode is None:
        print(f'Oops, {p1} timeouts!')
        p1.terminate()
 