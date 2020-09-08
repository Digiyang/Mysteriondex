#!/bin/bash

  	if [ $# -lt 3 ]
then
	echo "Du musst mindestens 3 Parameter eingeben" 
else 
	frage=$1
	antwort1=$2
	antwort2=$3
	clear
	echo $frage
	read antwort

	if [ "$antwort" = "$antwort1" ]
	then
		exit 0
	elif [  "$antwort" = "$antwort2" ]
	then
		exit 1
	else
		sh $0 "$frage" "$antwort1" "$antowrt2"
	fi
fi
