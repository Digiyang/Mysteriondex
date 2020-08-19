#!/bin/sh

usage(){
	echo "Usage $0 para1 para2 [para3 para4]... " >&2
	exit 1
}

Numb=$(echo $(($#%2)))

if [ $Numb -ne 0 ] ;then
	usage
fi

x=0
for i in $@;do

	if [ $((x%2)) -eq 0 ];then
		echo -n  $i=
	else 
		echo $i
	fi
x=$(($x+1))
done
