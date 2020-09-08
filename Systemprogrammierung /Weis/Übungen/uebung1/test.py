div = lambda x,y : x/y
test = ((666, 3),(69, '0'), (42, 0))
try:
	try:
		for a,b in test:
			try:
				print (a,b)
				print div(a,b)
			finally: 
				print 'division'
	except:
		print 'fehler' 
		raise ZeroDivisionError
except ZeroDivisionError:
	print 'nihct null'
finally:
	print 'aufrumen'
print 'ende'
	
