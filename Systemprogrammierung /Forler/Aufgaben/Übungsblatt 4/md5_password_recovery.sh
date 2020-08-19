#!/bin/bash

usage()
{
	echo " $0<Wörteliste> <Passwörter>" >&2
}
if [ $# -ne 2 ];then
	usage
fi

for PWL in $(cat $1);do	
	
	hash=$(echo -n  $PWL | md5sum | cut -d " " -f 1  )
	echo " $(grep $hash $2	| wc -l ),\"$PWL\",\"$hash\"" >> "tmp.txt"

done

	sort -t "," -nrk1,1 "tmp.txt"
	rm tmp.txt
