from socket import *

serverName="127.0.0.1"
serverPort = 12000
#clientSocket = socket(socket.AF_INET, socket.SOCK_DGRAM)
clientSocket = socket(AF_INET, SOCK_DGRAM)

message = input("Input lowercase sentence:")
clientSocket.sendto(message.encode('utf-8'),(serverName, serverPort)) 

clientSocket.settimeout(100)
print ("Current socket timeout: %s" ,clientSocket.gettimeout() )

modifiedMessage, serverAddress = clientSocket.recvfrom(2048) 
print (modifiedMessage)
clientSocket.close()

