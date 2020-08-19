
import os
import cx_Oracle

duration = 1
freq = 440

connection = cx_Oracle.connect('s864976/student@localhost:1521/oracle')
cursor = connection.cursor()

male = "male"
female = "female"

cursor.execute('select PATIENTNR from PATIENT')
result = cursor.fetchall()
for row in result:
    findqueries = ("select QUERY from AOLDATA.QUERYDATA where ANONID = :1")
    addasmale = ("update PATIENT set GESCHLECHT = 'm' where PATIENTNR =:1")
    addasfemale = ("update PATIENT set GESCHLECHT = 'w' where PATIENTNR =:1")

    cursor.execute(findqueries, (row))
    result2 = cursor.fetchall()
    for row2 in result2:
        rowtostring = ''.join(row2)
        if (rowtostring.find(male) > 0):
            cursor.execute(addasmale, (row))
            
                          

cursor.execute('SELECT * FROM PATIENT')
result = cursor.fetchall()

for row in result:
    print(row)


connection.commit()

os.system('play --no-show-progress --null --channels 1 synth %s sine %f' % (duration, freq))
cursor.close()
connection.close()
