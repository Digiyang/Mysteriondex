#https://www.python-course.eu/threads.php
import socket
import sys
import threading

class ClientThread(threading.Thread):
    def __init__(self,client):
        threading.Thread.__init__(self)
        self.clientsocket = client
    def run(self):
        while True:
            data = self.clientsocket.recv(1024)
            msg = data.decode("utf8")
            if msg == 'notify':
                print(msg)
            elif msg =='group leave ack':
                print ("from client", msg)
                self.clientsocket.close()
                print ("Client disconnected...")
                sys.exit()
"""x = threading.Thread(target=thread_function, args=(1,))
    logging.info("Main    : before running thread")
    x.start()
    logging.info("Main    : wait for the thread to finish")
    # x.join()
    logging.info("Main    : all done")"""
def receive(msg):
    protocol=msg.split('\\n')[0]
    request=msg.split('\\n')[1]
    dslp=msg.split('\\n')[2]
    last=msg.split('\\n')[3]
    print(protocol_response)
    print(request_response)
    print(dslp_response)
    print(last)

def Main():
    # Create a TCP/IP socket
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # Connect the socket to the port on the server
    server_address = (sys.argv[1], int(sys.argv[2]))
    print('Connected to the server {}:{}'.format(*server_address))
    client.connect(server_address)
    connection = ClientThread(client)
    connection.start()
    dslp_protocol = b'dslp-3.0\r\n'
    join = b'group join\r\n'
    leave = b'group leave\r\n'
    notify = b'group notify\r\n'
    end = b'dslp-body\r\n'
    message=None

    try:    
    	#send join request
    	client.sendall(dslp_protocol)
    	client.sendall(join)
    	groupname = b'Uebung\r\n'
    	client.sendall(groupname)
    	client.sendall(end) 
        #Send group Notify request
    	client.sendall(dslp_protocol)
    	client.sendall(notify)
    	client.sendall(groupname)
    	client.sendall(b'1\r\n')
    	client.sendall(end)
    	client.sendall(b'Welcome\r\n')
    	while message != 'x': 
            message = input("Put your message: ")
            client.sendall(dslp_protocol)
            client.sendall(notify)
            client.sendall(groupname)
            client.sendall(b'1\r\n')
            client.sendall(end)
            #message = bytes(message+ "\r\n",'UTF-8')
            client.sendall(bytes(message+ "\r\n","UTF-8"))

            if message == 'x':
        	#Send leave request
            	client.sendall(dslp_protocol)
            	client.sendall(leave)
            	client.sendall(groupname) 
            	client.sendall(end)
            	return
            	break 
    
    finally:
        client.close()

if __name__ == "__main__":
    Main()
