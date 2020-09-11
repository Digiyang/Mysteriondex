import sys

l= len(sys.argv)
if l > 3 :
    print(str(sys.argv[-2 : -1])) 
    print(str(sys.argv[-1 : ]))