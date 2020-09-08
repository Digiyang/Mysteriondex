#!/bin/sh
time=$(date +%H)
# check if time smaller than 14
if [ $time -lt 14 ]
then
	echo "Good morning sunshine"
else
	echo "Good afternoon you lazy ass"
fi
