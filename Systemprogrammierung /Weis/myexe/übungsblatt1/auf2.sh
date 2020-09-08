#!/bin/bash
if [ $(expr $# % 2) == 0 ]
then
	echo "$@"
else
	echo "not even number">&2
fi
