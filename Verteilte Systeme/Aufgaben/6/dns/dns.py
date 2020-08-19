import sys
import dns.resolver

domain = (sys.argv[1])

print(domain)

print("Mailserver: ")

for rdata in dns.resolver.query(sys.argv[1], 'MX'):
    print(rdata.to_text())

print("DNS-Server: ")
for rdata in dns.resolver.query(sys.argv[1], 'NS'):
    print(rdata.to_text())

print("WWW-Server: ")

for rdata in dns.resolver.query(sys.argv[1],'A' ):
        print("IPv4: ", rdata.to_text())
try:
    for rdata in dns.resolver.query(sys.argv[1],"AAAA" ):
        print("IPv6: ", rdata.to_text())
except:
    print("IPv6: ------")