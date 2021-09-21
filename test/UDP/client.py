from socket import *

serverName = "127.0.0.1"
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
messagetoserver = input("Enter Message for Server: ")
clientSocket.send(messagetoserver.encode('utf-8'))
replyfromserver = clientSocket.recv(1024)
print ("Reply Message from Server: "), replyfromserver
clientSocket.close()