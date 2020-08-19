

import cx_Oracle

connection = cx_Oracle.connect('s864976/student@localhost:1521/oracle')
cursor = connection.cursor()

cursor.execute('insert into BEHANDLUNG (NAME_DER_BEHANDLUNG, KOSTEN) VALUES (\'surgery\', 39891)')
cursor.execute('insert into BEHANDLUNG (NAME_DER_BEHANDLUNG, KOSTEN) VALUES (\'radiation\', 35000)')
cursor.execute('insert into BEHANDLUNG (NAME_DER_BEHANDLUNG, KOSTEN) VALUES (\'chemotherapy\', 30000)')
cursor.execute('insert into BEHANDLUNG (NAME_DER_BEHANDLUNG, KOSTEN) VALUES (\'immunotherapy\', 52000)')
cursor.execute('insert into BEHANDLUNG (NAME_DER_BEHANDLUNG, KOSTEN) VALUES (\'targeted\', 65000)')
cursor.execute('insert into BEHANDLUNG (NAME_DER_BEHANDLUNG, KOSTEN) VALUES (\'hormone\', 97066)')
cursor.execute('insert into BEHANDLUNG (NAME_DER_BEHANDLUNG, KOSTEN) VALUES (\'stemcell\', 25000)')
cursor.execute('insert into BEHANDLUNG (NAME_DER_BEHANDLUNG, KOSTEN) VALUES (\'precisionmedicine\', 141440)')

connection.commit()
cursor.execute('SELECT * FROM BEHANDLUNG')
result = cursor.fetchall()

for row in result:
    print(row)

cursor.close()
connection.close()
