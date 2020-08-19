import os
import cx_Oracle

duration = 1
freq = 440

print("Processing...")

connection = cx_Oracle.connect('s864976/student@localhost:1521/oracle')
cursor = connection.cursor()


#surgery
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%surgery%cancer%\' or QUERY like \'%cancer%surgery%\' and ANONID not in (select PATIENTNR as ANONID from BEKOMMT_BEHANDLUNG)')
result = cursor.fetchall()
for row in result:
    addbehandlung = ("insert into BEKOMMT_BEHANDLUNG (NAME_DER_BEHANDLUNG, PATIENTNR) VALUES( 'surgery', :1)")
    cursor.execute('select PATIENTNR as ANONID from PATIENT')
    result = cursor.fetchall()
    for row2 in result:    
        if (row2 == row):
            cursor.execute(addbehandlung,(row))

#chemotherapy
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%chemotherapy%\'')
result = cursor.fetchall()
for row in result:
    addbehandlung = ("insert into BEKOMMT_BEHANDLUNG ( NAME_DER_BEHANDLUNG, PATIENTNR) VALUES( 'chemotherapy', :1)")
    cursor.execute('select PATIENTNR as ANONID from PATIENT')
    result = cursor.fetchall()
    for row2 in result:    
        if (row2 == row):
            cursor.execute(addbehandlung,(row))

#immunotherapy
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%immunotherapy%\'')
result = cursor.fetchall()
for row in result:
    addbehandlung = ("insert into BEKOMMT_BEHANDLUNG (NAME_DER_BEHANDLUNG, PATIENTNR) VALUES( 'immunotherapy', :1)")
    cursor.execute('select PATIENTNR as ANONID from PATIENT')
    result = cursor.fetchall()
    for row2 in result:    
        if (row2 == row):
            cursor.execute(addbehandlung,(row))

#targeted
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%targeted%cancer%\' or QUERY like \'%cancer%targeted%\'')
result = cursor.fetchall()
for row in result:
    addbehandlung = ("insert into BEKOMMT_BEHANDLUNG (NAME_DER_BEHANDLUNG, PATIENTNR) VALUES( 'targeted', :1)")
    cursor.execute('select PATIENTNR as ANONID from PATIENT')
    result = cursor.fetchall()
    for row2 in result:    
        if (row2 == row):
            cursor.execute(addbehandlung,(row))

#hormone
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%hormone%cancer%therapy%\' or QUERY like \'%cancer%therapy%hormone%\'')
result = cursor.fetchall()
for row in result:
    addbehandlung = ("insert into BEKOMMT_BEHANDLUNG (NAME_DER_BEHANDLUNG, PATIENTNR) VALUES( 'hormone', :1)")
    cursor.execute('select PATIENTNR as ANONID from PATIENT')
    result = cursor.fetchall()
    for row2 in result:    
        if (row2 == row):
            cursor.execute(addbehandlung,(row))

#stemcell
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%stemcell%cancer%\' or QUERY like \'%cancer%stemcell%\'')
result = cursor.fetchall()
for row in result:
    addbehandlung = ("insert into BEKOMMT_BEHANDLUNG (NAME_DER_BEHANDLUNG, PATIENTNR) VALUES( 'stemcell', :1)")
    cursor.execute('select PATIENTNR as ANONID from PATIENT')
    result = cursor.fetchall()
    for row2 in result:    
        if (row2 == row):
            cursor.execute(addbehandlung,(row))

#precisionmedicine
cursor.execute('select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%precisionmedicen%cancer%\' or QUERY like \'%cancer%precisionmedicine%\'')
result = cursor.fetchall()
for row in result:
    addbehandlung = ("insert into BEKOMMT_BEHANDLUNG (NAME_DER_BEHANDLUNG, PATIENTNR) VALUES( 'precisionmedicine', :1)")
    cursor.execute('select PATIENTNR as ANONID from PATIENT')
    result = cursor.fetchall()
    for row2 in result:    
        if (row2 == row):
            cursor.execute(addbehandlung,(row))

cursor.execute('SELECT * FROM  BEKOMMT_BEHANDLUNG')
result = cursor.fetchall()

for row in result:
    print(row)

connection.commit()

os.system('play --no-show-progress --null --channels 1 synth %s sine %f' % (duration, freq))
cursor.close()
connection.close()
