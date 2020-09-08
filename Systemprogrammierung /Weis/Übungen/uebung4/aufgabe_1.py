import os
import pickle
import pprint

woerterbuch = {}

if os.path.isfile("./pickleDump.pickle"):
	f = open("./pickleDump.pickle") 
	woerterbuch = pickle.load(f) 



for root, dirs, files in os.walk('.'):
	for filename in files: 
		ext = filename.split(".")[1]
		if ext == "txt":
			fobj = open(root+"/"+filename, "r") 
			for line in fobj:
				line = line.strip() 
				woerter = line.split(" ") 
				for wort in woerter:		
					if len(wort) > 0:				
						if wort in woerterbuch:
							if root+"/"+filename not in woerterbuch[wort]:	 
								woerterbuch[wort].append(root+"/"+filename)
						else:
					 		woerterbuch[wort] = [root+"/"+filename]	 
f = open("pickleDump.pickle", "w") 
pickle.dump(woerterbuch, f)
pprint.pprint(woerterbuch)
