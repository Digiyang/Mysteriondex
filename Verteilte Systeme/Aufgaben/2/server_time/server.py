#socket_echo_client_explicit.py

import socket
import sys
import datetime
import time

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the port on the server
# given by the caller
server_address = (sys.argv[1], int(sys.argv[2]))
print('Verbunden zu {}:{}'.format(*server_address))
sock.connect(server_address)

try:

    
    message_a = b'dslp-3.0\r\n'
    message_b = b'request time\r\n'
    message_c = b'dslp-body\r\n'
    sock.sendall(message_a)
    sock.sendall(message_b)
    sock.sendall(message_c)

    amount_received = 0
    amount_expected = len(message_a)
    while amount_received < amount_expected:
        data = sock.recv(1024)
        data_string = format(data)
        amount_received += len(data)
        data_string1 = data_string.split('\\n')[3]
        data_string2 = data_string1.split('\\r')[0]
        print('Aktuelle Zeit auf dem Server: %s'%(data_string2))
        yy = data_string2.split('-')[0] #YER
        mm = data_string2.split('-')[1] #MONAT
        dd_swap = data_string2.split('-')[2]
        dd = dd_swap.split('T')[0]
       
        hh_swap = dd_swap.split('T')[1]
        hh = hh_swap.split(':')[0]
        mi = hh_swap.split(':')[1]
        ss_swap = hh_swap.split(':')[2]
        ss = ss_swap.split('+')[0]
        t = datetime.time(int(hh),int(mi), int(ss))
        d = datetime.date(int(yy),int(mm),int(dd))
        td = datetime.datetime(int(yy),int(mm),int(dd),int(hh),int(mi),int(ss))

        
        print(d,t)
        
        print(td.ctime()+ " CEST")
        
finally:
    sock.close()

