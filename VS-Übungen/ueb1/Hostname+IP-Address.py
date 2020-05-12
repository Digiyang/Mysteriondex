# Importing Socket Library 	
import socket
# Function(Hostname+Address)
def gethostname():
	try:		
		host_name = socket.gethostname()
		Ip_address = socket.gethostbyname(host_name)
		print("Name of Localhost is: {}".format(host_name))
		print("IP Address of Localhost is: {}".format(Ip_address))
	except:
		print("Unable to get Hostname and IP address")

# Function Call
gethostname()