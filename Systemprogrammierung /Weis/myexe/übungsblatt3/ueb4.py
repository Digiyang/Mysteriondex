d = {"OS": ("Linux", "Open Solaris", ["Free BSD","Open BSD"],{"Minix":["V2","V3"]})}

print (d["OS"][3])
print (d["OS"][2][-1:][0][-3:])
print (d.keys())
print (d.values())
print (d.items())