#!/bin/bash
s=""
for i in $@
do
	s="$i $s"
done
echo $s
