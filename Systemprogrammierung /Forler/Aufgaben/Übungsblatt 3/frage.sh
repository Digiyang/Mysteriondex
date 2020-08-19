#!/bin/sh


usage()
{

	echo "$0: <frage> <ja> <nein> " >&2 
	exit 1

}

if [ $# -ne 3  ] ;then
	usage
fi

echo $1
read ans
while [ $ans != $2 ] && [ $ans != $3 ] ;do
	echo $1
	read ans
done

if [ $ans = $1 ];then
	exit 0
else
	exit 1

fi



