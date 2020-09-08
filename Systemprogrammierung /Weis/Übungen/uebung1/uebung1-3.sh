#!/bin/bash
newstring=""
for i in $@
do
newstring="$i $newstring"
done
echo $newstring
