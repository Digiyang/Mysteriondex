#!/bin/sh
i=0
while [ $i -le 10 ]
do
# the expr command evaluates a given expression and displays it's corresponding output
	i=$(expr $i + 1 )
	echo "$i"
done
