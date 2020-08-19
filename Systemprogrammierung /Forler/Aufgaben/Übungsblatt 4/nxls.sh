#!/bin/bash

usage()
{
	echo "usage: $0 <Directory> " > /dev/stderr
	exit 1
}

if [ $# -ne 1 ] ; then
	usage
fi

for i in $(ls $1);do
	if [ -f $1/$i -a ! -x $1/$i ];then
	       echo $i
       fi
done       
