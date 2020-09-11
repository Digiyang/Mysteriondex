import os 

files_list = os.listdir()
for x in files_list:
    if len(x) > 3 and len(x) < 6:
        print(x)