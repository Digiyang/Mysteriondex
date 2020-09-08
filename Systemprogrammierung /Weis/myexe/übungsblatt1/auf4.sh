#!/bin/bash
list=$(ls)
for i in $list
do
l=$(expr $(echo $i | wc -c) - 1 )
if [ $l -gt 3 -a $l -lt 6 ]
then
	echo "$i"
fi
done
