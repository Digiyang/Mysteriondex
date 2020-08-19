

import os
import cx_Oracle

duration = 1
freq = 440

connection = cx_Oracle.connect('s864976/student@localhost:1521/oracle')
cursor = connection.cursor()

male = "male"
female = "female"

cursor.execute('select ANONID from (select distinct ANONID from AOLDATA.querydata where QUERY like \'%support group%\' and QUERY like \'%cancer%\' and ANONID in (select patientnr as annonid from patient))')
result = cursor.fetchall()
for row in result:
    addgroup = ("update PATIENT set GRUPPENNR = 1 where PATIENTNR =:1")
    cursor.execute(addgroup, (row))
 
cursor.execute('SELECT * FROM PATIENT WHERE GRUPPENNR = 1')
result = cursor.fetchall()

for row in result:
    print(row)


connection.commit()

os.system('play --no-show-progress --null --channels 1 synth %s sine %f' % (duration, freq))
cursor.close()
connection.close()
