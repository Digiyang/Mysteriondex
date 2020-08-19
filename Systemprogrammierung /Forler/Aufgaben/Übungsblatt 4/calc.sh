#!/bin/bash

usage()
{
    echo "usage: $0 <int> <operator> <int>" >&2;
    echo "operators: MULT, ADD, SUB, DIV, MOD and EXP"
    exit 1
}

if [ $# -ne 3 ]; then
    usage
fi

case $2 in
    "MULT")
        echo $(($1 * $3));;
    "ADD")
        echo $(($1 + $3));;
    "SUB")
        echo $(($1 - $3));;
    "DIV")
        echo $(($1 / $3));;
    "MOD")
        echo $(($1 % $3));;
    "EXP")
        echo $(($1 ** $3));;
    *)
        usage
esac

exit 0

