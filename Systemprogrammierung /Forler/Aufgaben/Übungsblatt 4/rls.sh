#!/bin/sh
usage()
{
    echo "usage: rls.sh <min> <max>" >&2;
    exit 1
}


#main
if [ $# -ne 2 ]; then
    usage
fi

min=$1
max=$2

for filename in $(ls *); do
	ln=$(echo -n $filename |  wc -m )
	if [ $ln -ge $min  -a  $ln -lt $max ]; then
		echo $filename $ln
	fi
done
