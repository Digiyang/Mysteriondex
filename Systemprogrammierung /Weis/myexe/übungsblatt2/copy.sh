#!/bin/bash
if [ $# -gt 0 ]
then
f=$(ls *.$1)
sh frage.sh "Do you want to make a backup ?" "Ja" "Nein"
if [ $? = 0 ]
then
	if [ ! -d backup/ ]
	then  
		mkdir backup
	fi
	for i in $f
	do
	cp $i backup/
	done
	fi
fi
