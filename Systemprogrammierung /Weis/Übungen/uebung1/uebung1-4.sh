#!/bin/bash
ls=$(ls)
for i in $ls
do
length=$(expr $(echo $i | wc -c) - 1 )
if [ $length -gt 3  -a  $length -lt 6 ]
then
	echo "$i" 
fi
done
