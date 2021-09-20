from socket import *

serverName="127.0.0.1"
serverPort = 2500

def sent(x):
    message = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    print("times : ",x)
    print("I send message to 127.0.0.1:2500")
    print("It says => ",message)
    clientSocket = socket(AF_INET, SOCK_DGRAM)
    clientSocket.sendto(message.encode('utf-8'),(serverName, serverPort)) 
    modifiedMessage, serverAddress = clientSocket.recvfrom(2048) 
    clientSocket.close()


for x in range(0, 2):
    sent(x)

print ("close")
