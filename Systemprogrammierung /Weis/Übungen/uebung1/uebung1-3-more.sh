#!/bin/bash
i=$#
while [ $i -gt 0 ]
do
a=0
	for c in $@
	do
		a=$(expr $a + 1)
		if [ $a -eq $i ]
		then
			echo "$i $c"
		fi  		
	done
i=$(expr $i - 1)
done

