import cx_Oracle

connection = cx_Oracle.connect('s864976/student@localhost:1521/oracle')
cursor = connection.cursor()


cursor.execute('insert into PATIENT (PATIENTNR) select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%bladder%cancer%\' OR QUERY like \'%cancer%bladder%\'and ANONID not in (select PATIENTNR as ANONID from PATIENT)')
cursor.execute('insert into PATIENT (PATIENTNR) select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%breast%cancer%\' or QUERY like \'%cancer%breast%\' and ANONID not in (select PATIENTNR as ANONID from PATIENT)')
cursor.execute('insert into PATIENT (PATIENTNR) select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%colorectal%cancer%\' or QUERY like \'%cancer%colorectal%\' or QUERY like \'%bowel%cancer%\' or QUERY like \'%cancer%bowel%\' and ANONID not in (select PATIENTNR as ANONID from PATIENT)')
cursor.execute('insert into PATIENT (PATIENTNR) select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%kidney%cancer%\' or QUERY like \'%cancer%kidney%\' and ANONID not in (select PATIENTNR as ANONID from PATIENT)')
cursor.execute('insert into PATIENT (PATIENTNR) select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%lung%cancer%\' or QUERY like \'%cancer%lung%\' and ANONID not in (select PATIENTNR as ANONID from PATIENT)')
cursor.execute('insert into PATIENT (PATIENTNR) select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%lymphoma%cancer%\' or QUERY like \'%cancer%lymphoma%\' and ANONID not in (select PATIENTNR as ANONID from PATIENT)')
cursor.execute('insert into PATIENT (PATIENTNR) select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%melanoma%cancer%\' or QUERY like \'%cancer%melanoma%\' and ANONID not in (select PATIENTNR as ANONID from PATIENT)')
cursor.execute('insert into PATIENT (PATIENTNR) select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%oral%cancer%\' or QUERY like \'%cancer%oral%\' or QUERY like \'%oesophageal%cancer%\' or QUERY like \'%cancer%oesophageal%\' and ANONID not in (select PATIENTNR as ANONID from PATIENT)')
cursor.execute('insert into PATIENT (PATIENTNR) select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%pancreatic%cancer%\' or QUERY like \'%cancer%pancreatic%\' and ANONID not in (select PATIENTNR as ANONID from PATIENT)')
cursor.execute('insert into PATIENT (PATIENTNR) select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%prostate%cancer%\' or QUERY like \'%cancer%prostate%\' and ANONID not in (select PATIENTNR as ANONID from PATIENT)')
cursor.execute('insert into PATIENT (PATIENTNR) select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%thyroid%cancer%\' or QUERY like \'%cancer%thyroid%\' and ANONID not in (select PATIENTNR as ANONID from PATIENT)')
cursor.execute('insert into PATIENT (PATIENTNR) select distinct ANONID from AOLDATA.QUERYDATA where QUERY like \'%uterine%cancer%\' or QUERY like \'%cancer%uterine%\' and ANONID not in (select PATIENTNR as ANONID from PATIENT)')
connection.commit()
cursor.execute('SELECT * FROM PATIENT')
result = cursor.fetchall()

for row in result:
    print(row)

cursor.close()
connection.close()


