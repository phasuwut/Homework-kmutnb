from socket import *

serverPort = 2500
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print("The server is ready to receive")

while 1:
    message, clientAddress = serverSocket.recvfrom(2048)
    print(message)
    print(serverSocket)
    modifiedMessage = message.upper() 
    serverSocket.sendto(modifiedMessage, clientAddress)

