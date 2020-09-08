#!/bin/bash
# all calls parameters as a sequence of strings
echo $@ 
i=-1
while [[ $i -le $# ]]
do
	i=$(expr $i + 1)
	shift
	echo $@
done 
