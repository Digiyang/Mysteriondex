import sys

if ((len(sys.argv)-1) % 2) != 0:
	 sys.stderr.write("Dieses Script braucht eine grade anzahl von Parametern \n")
	 sys.exit(1)
