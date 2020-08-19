#!/bin/sh
for i in $(ls *$1);do
	echo "wollen Sie die Datei $i speichern(ja/nein)?"
	read ans
	if [ $ans = 'nein'  ]; then
	continue
	elif [ $ans = 'ja' ]; then
		ls backup || mkdir backup
		cp -r $i ./backup
	fi	

done



