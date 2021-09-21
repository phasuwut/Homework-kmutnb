from socket import *
import time

serverPort = 2500
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print("The server is ready to receive")

def convertTuple(tup):
    st = ''.join(map(str, tup))
    return st

while 1:
    time_string = time.asctime()
    print(time_string)

    message, clientAddress,  = serverSocket.recvfrom(2048)
    print("client sent => ",message)
    time.sleep(1)

    clientAddressString = convertTuple(clientAddress)
    messageOtput=time_string+" server'Address :=> 127.0.0.1:"+ str(serverPort) +", Your'Address :=> " + clientAddressString
    
    serverSocket.sendto(messageOtput.encode('utf-8'), clientAddress)

