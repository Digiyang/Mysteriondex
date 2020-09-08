#!/bin/bash
if [ $# -lt 3 ]
then
	echo "Need 3 parameters!"
else
	read -p "$1" reply
	if [ "$reply" = "$2" ]
	then 
		exit 0
	elif [ $reply = "$3" ] 
	then
		exit 1
	else 
		sh $0 "$1" "$2" "$3"
	fi
fi
