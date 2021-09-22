from socket import *
import time

serverPort = 12000
serverIp = '127.0.0.1'

serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind((serverIp,serverPort))
serverSocket.listen(1)
print ("The server is ready to receive")

def convertTuple(tup):
    st = ':'.join(map(str, tup))
    return st


while 1:
    connectionSocket, addr = serverSocket.accept()
    message = connectionSocket.recv(1024) 
    
    """ time.sleep(3) """

    clientAddressToString = convertTuple(addr)
    time_string = time.asctime()
    print("client sent => ",message)
    print(time_string)
    print(clientAddressToString)
    print("")
    messageOtput=time_string+" server'Address :=> 127.0.0.1:"+ str(serverPort) +", Your'Address :=> " + clientAddressToString
    
    connectionSocket.send(messageOtput.encode('utf-8')) 
    connectionSocket.close()
