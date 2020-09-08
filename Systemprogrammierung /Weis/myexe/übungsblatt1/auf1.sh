#!/bin/bash
if [ $# -gt 2 ]
then
i=0
l=$(expr $# - 2)
for arg in $*
do
	i=$(expr $i + 1)
	if [ $i -gt $l ]
	then
		echo $arg
	fi
done
fi
