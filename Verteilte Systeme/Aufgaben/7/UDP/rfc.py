import socket
import sys
import time
import struct

hostname = (sys.argv[1])
port = 37

host = socket.gethostbyname(hostname)

rfc = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
rfc.sendto(b'', (host, port))
print ("looking for replies; press Ctrl-C to stop")

buf = rfc.recvfrom(2048)[0]
if len(buf) != 4:
    print ("Wrong sized reply %d: %s" % (len(buf), buf))
    sys.exit(1)

secs = struct.unpack('!I', buf)[0]
secs -= 2208988800
print (time.ctime(int(secs)))