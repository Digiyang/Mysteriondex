#!/bin/bash
if [  $(expr $# % 2) -ne 0 ]
then
echo "Nicht grade!">&2
fi


