#!/bin/bash

if [ $# -gt 0 ]
then
datein=$(ls *.$1)
sh uebung2-1.sh "Möchten sie die Datein nach Backup kopieren ?" "Ja" "Nein"
	if [ $? = 0 ]
	then
	if [ ! -d backup/ ]
	then
	mkdir backup
	fi
	for i in $datein
	do
		cp $i backup/
	done
	fi
fi
