#!/bin/bash
if [ $# -gt 2 ]
then
i=0
last=$(expr $# - 2)
for a in $* 
do
i=$(expr $i + 1)
if [ $i -gt $last ]
then 
echo $a
fi
done
fi
