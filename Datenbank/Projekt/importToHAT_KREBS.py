import os
import cx_Oracle

duration = 1
freq = 440
#file_object = open("workfile.txt","w")

connection = cx_Oracle.connect('s864976/student@localhost:1521/oracle')
cursor = connection.cursor()

#bladder cancer
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%bladder%cancer%\' or QUERY like \'%cancer%bladder%\' and ANONID not in (select PATIENTNR as ANONID from HAT_KREBS)')
result = cursor.fetchall()
for row in result:
    addpatient = ("insert into HAT_KREBS (KREBSNAME, PATIENTNR) VALUES( 'bladder', :1)")
    cursor.execute(addpatient, (row))

#breast cancer
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%breast%cancer%\' OR QUERY like \'%cancer%breast%\' and ANONID not in (select PATIENTNR as ANONID from HAT_KREBS)')
result = cursor.fetchall()
for row in result:
    addpatient = ("insert into HAT_KREBS (KREBSNAME, PATIENTNR) VALUES( 'breast', :1)")
    cursor.execute(addpatient, (row))

#colorectal cancer (synonim - bowel cancer)
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%colorectal%cancer%\' OR QUERY like \'%cancer%colorectal%\'  or QUERY like \'%bowel%colorectal%\' or QUERY like \'%cancer%bowel%\' and ANONID not in (select PATIENTNR as ANONID from HAT_KREBS)')
result = cursor.fetchall()
for row in result:
    addpatient = ("insert into HAT_KREBS (KREBSNAME, PATIENTNR) VALUES( 'colorectal', :1)")
    cursor.execute(addpatient, (row))

#kidney cancer
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%kidney%cancer%\' or QUERY like \'%cancer%kidney%\' and ANONID not in (select PATIENTNR as ANONID from HAT_KREBS)')
result = cursor.fetchall()
for row in result:
    addpatient = ("insert into HAT_KREBS (KREBSNAME, PATIENTNR) VALUES( 'kidney', :1)")
    cursor.execute(addpatient, (row))

#lung cancer
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%lung%cancer%\' or QUERY like \'%cancer%lung%\' and ANONID not in (select PATIENTNR as ANONID from HAT_KREBS)')
result = cursor.fetchall()
for row in result:
    addpatient = ("insert into HAT_KREBS (KREBSNAME, PATIENTNR) VALUES( 'lung', :1)")
    cursor.execute(addpatient, (row))

#lymphoma cancer
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%lymphoma%cancer%\' or QUERY like \'%cancer%lymphoma%\' and ANONID not in (select PATIENTNR as ANONID from HAT_KREBS)')
result = cursor.fetchall()
for row in result:
    addpatient = ("insert into HAT_KREBS (KREBSNAME, PATIENTNR) VALUES( 'lymphoma', :1)")
    cursor.execute(addpatient, (row))

#melanoma cancer
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%melanoma%cancer%\' or QUERY like \'%cancer%melanoma%\' and ANONID not in (select PATIENTNR as ANONID from HAT_KREBS)')
result = cursor.fetchall()
for row in result:
    addpatient = ("insert into HAT_KREBS (KREBSNAME, PATIENTNR) VALUES( 'melanoma', :1)")
    cursor.execute(addpatient, (row))

#oral cancer (synonim - bowel coesophageal)
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%oesophageal%cancer%\' OR QUERY like \'%cancer%oesophageal%\'  or QUERY like \'%oral%cancer%\' or QUERY like \'%cancer%oral%\' and ANONID not in (select PATIENTNR as ANONID from HAT_KREBS)')
result = cursor.fetchall()
for row in result:
    addpatient = ("insert into HAT_KREBS (KREBSNAME, PATIENTNR) VALUES( 'oral', :1)")
    cursor.execute(addpatient, (row))

#pancreatic cancer
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%pancreatic%cancer%\' or QUERY like \'%cancer%pancreatic%\' and ANONID not in (select PATIENTNR as ANONID from HAT_KREBS)')
result = cursor.fetchall()
for row in result:
    addpatient = ("insert into HAT_KREBS (KREBSNAME, PATIENTNR) VALUES( 'pancreatic', :1)")
    cursor.execute(addpatient, (row))

#prostate cancer
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%prostate%cancer%\' or QUERY like \'%cancer%prostate%\' and ANONID not in (select PATIENTNR as ANONID from HAT_KREBS)')
result = cursor.fetchall()
for row in result:
    addpatient = ("insert into HAT_KREBS (KREBSNAME, PATIENTNR) VALUES( 'prostate', :1)")
    cursor.execute(addpatient, (row))

#thyroid cancer
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%thyroid%cancer%\' or QUERY like \'%cancer%thyroid%\' and ANONID not in (select PATIENTNR as ANONID from HAT_KREBS)')
result = cursor.fetchall()
for row in result:
    addpatient = ("insert into HAT_KREBS (KREBSNAME, PATIENTNR) VALUES( 'thyroid', :1)")
    cursor.execute(addpatient, (row))

#uteriine cancer
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%uterine%cancer%\' or QUERY like \'%cancer%uterine%\' and ANONID not in (select PATIENTNR as ANONID from HAT_KREBS)')
result = cursor.fetchall()
for row in result:
    addpatient = ("insert into HAT_KREBS (KREBSNAME, PATIENTNR) VALUES( 'uterine', :1)")
    cursor.execute(addpatient, (row))

cursor.execute('SELECT * FROM HAT_KREBS')
result = cursor.fetchall()

for row in result:
#    file_object.write(row)
    print(row)

#file_object.close

connection.commit()

os.system('play --no-show-progress --null --channels 1 synth %s sine %f' % (duration, freq))
cursor.close()
connection.close()
