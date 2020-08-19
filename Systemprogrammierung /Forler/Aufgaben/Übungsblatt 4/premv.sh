#!/bin/sh

usage()
{
	echo "$0 <old-prefix> <new-prefix> " >&2
	exit 1
}

if [ $# -ne 2 ];then
	usage
fi

for filename in $(ls $1.*);do
	name=$(echo $filename | sed s/$1/$2/ ) #sed s(ersetzen)/(bs1)/(bs2)/global sed -r 's///'
	mv $filename $name
done
