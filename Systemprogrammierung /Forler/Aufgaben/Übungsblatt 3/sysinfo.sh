#/bin/bash

echo $(cat /proc/cpuinfo | grep -e "model name")
echo $(cat /proc/cpuinfo | grep -e "cpu MHz")
echo $(uname) $(uname -r)
