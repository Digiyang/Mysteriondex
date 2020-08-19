#!/bin/sh


last=$(echo $@ | cut -d " " -f $#)
Vlast=$(echo $@ | cut -d " " -f $(($#-1)))

echo "Before last: $Vlast"
echo "Last parameter: $last"
