import socket
import sys
import threading
import time

protocol = b"dslp-3.0\r\n"
user_join = b"user join\r\n"
user_leave = b"user leave\r\n"
user_text_notify = b"user text notify\r\n"
#error = b"error\r\n"
end = b"dslp-body\r\n"
global error
error = False


class ClientThread(threading.Thread):
    def __init__(self,client):
        threading.Thread.__init__(self)
        self.clientsocket = client
    def run(self):
        global error
        while True:
            data = self.clientsocket.recv(1024)
            msg = format(data)
            splitted_msg = msg.split("\\r\\n")
            #if len(msg) > 1:            
            #    print(msg)
            if "user text notify" in msg:
                print('('+splitted_msg[2]+') ' + splitted_msg[6])
            elif "error" in msg:
                print(splitted_msg[-2])
                print("server ended connection")
                error = True
                sys.exit()
            elif "user leave ack" in msg:
                print("from client: " + splitted_msg[1] + ' ' + splitted_msg[2])
                self.clientsocket.close()
                print("Client disconnected...")
                sys.exit()
    
class Dslp:
	def __init__(self, protocol, user_join, user_leave, user_text_notify, end):
		self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		self.server_name = sys.argv[1]
		self.port = int(sys.argv[2])
		self.username = bytes((sys.argv[3]+"\r\n").encode("UTF-8"))
		self.server = (self.server_name, self.port)
		self.protocol = protocol
		self.user_join = user_join
		self.user_leave = user_leave
		self.user_text_notify = user_text_notify
		self.end = end

	def connection(self):
		self.client.connect(self.server)
		print("connected to the server {}:{}".format(*self.server))
		print("Connected as:",self.username.decode("UTF-8"))
	
	

	def user_leave_request(self):
		self.client.sendall(self.protocol)
		self.client.sendall(self.user_leave)
		self.client.sendall(self.username)
		self.client.sendall(self.end)

	def text_notify(self, receiver, message):
		line_number = message.count("\n") + 1
		self.client.sendall(self.protocol)
		self.client.sendall(self.user_text_notify)
		self.client.sendall(self.username)
		self.client.sendall(receiver)
		self.client.sendall(bytes(str(line_number)+"\r\n", "UTF-8"))
		self.client.sendall(self.end)
		self.client.sendall(bytes(message+ "\r\n","UTF-8"))

	def send_message(self):
		text = input(">")
		position = text.find(":")
		if position > 0 :
			receiver = text[:position]
			message = text[position+1:]
			return receiver, message
		else:
			if text != 'x':
				print("error")
			return None, text

	def user_join_request(self):
		self.client.sendall(self.protocol)
		self.client.sendall(self.user_join)
		self.client.sendall(self.username)
		self.client.sendall(self.end)
		return self.client

def Main():
	print(sys.argv[0])
	global error
	message = None
	server = Dslp(protocol, user_join, user_leave, user_text_notify, end)
	server.connection()
	server.user_join_request()
	thr_connection = ClientThread(server.client)
	thr_connection.start()
	
	try:
		
		time.sleep(0.5)
		while message != "x" and not error:
			receiver, message = server.send_message()
			if receiver is not None:
				receiver = bytes(receiver+"\r\n","UTF-8")
				server.text_notify(receiver,message)

			time.sleep(0.5)
		
		server.user_leave_request()
	
	finally:
		thr_connection.join()
		server.client.close()
			
if __name__ == "__main__":
    Main()


		


