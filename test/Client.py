from socket import *

serverName="127.0.0.1"
serverPort = 2501

def sent(x):
    message = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    print("times : ",x)
    print("I send message to 127.0.0.1:2500")
    print("It says => ",message)
    clientSocket = socket(AF_INET, SOCK_DGRAM)
    clientSocket.sendto(message.encode('utf-8'),(serverName, serverPort)) 
    
"""     print ("timeout: %s" ,clientSocket.gettimeout() )
    clientSocket.settimeout(500)
    print ("timeout: %s" ,clientSocket.gettimeout() ) """


    modifiedMessage, serverAddress = clientSocket.recvfrom(2048) 
    print (modifiedMessage)
    print (serverAddress)
    clientSocket.close()


for x in range(0, 1):
    sent(x)

