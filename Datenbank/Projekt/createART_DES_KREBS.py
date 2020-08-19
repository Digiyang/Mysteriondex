
import cx_Oracle

connection = cx_Oracle.connect('s864976/student@localhost:1521/oracle')
cursor = connection.cursor()

cursor.execute('insert into ART_DES_KREBS (KREBSNAME, STERBLICHKEIT) VALUES (\'bladder\', 50)')
cursor.execute('insert into ART_DES_KREBS (KREBSNAME, STERBLICHKEIT) VALUES (\'breast\', 78)')
cursor.execute('insert into ART_DES_KREBS (KREBSNAME, STERBLICHKEIT) VALUES (\'colorectal\', 57)')
cursor.execute('insert into ART_DES_KREBS (KREBSNAME, STERBLICHKEIT) VALUES (\'kidney\', 50)')
cursor.execute('insert into ART_DES_KREBS (KREBSNAME, STERBLICHKEIT) VALUES (\'lung\', 5)')
cursor.execute('insert into ART_DES_KREBS (KREBSNAME, STERBLICHKEIT) VALUES (\'lymphoma\', 63)')
cursor.execute('insert into ART_DES_KREBS (KREBSNAME, STERBLICHKEIT) VALUES (\'melanoma\', 90)')
cursor.execute('insert into ART_DES_KREBS (KREBSNAME, STERBLICHKEIT) VALUES (\'oral\', 12)')
cursor.execute('insert into ART_DES_KREBS (KREBSNAME, STERBLICHKEIT) VALUES (\'pancreatic\', 01)')
cursor.execute('insert into ART_DES_KREBS (KREBSNAME, STERBLICHKEIT) VALUES (\'prostate\', 84)')
cursor.execute('insert into ART_DES_KREBS (KREBSNAME, STERBLICHKEIT) VALUES (\'thyroid\', 85)')
cursor.execute('insert into ART_DES_KREBS (KREBSNAME, STERBLICHKEIT) VALUES (\'uterine\', 78)')

connection.commit()
cursor.execute('SELECT * FROM ART_DES_KREBS')
result = cursor.fetchall()

for row in result:
    print(row)

cursor.close()
connection.close()


