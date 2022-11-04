#!/bin/bash

a=$1
op=$2
b=$3

case $2 in
	'+') result=`expr $1 + $3`;;
	'-') result=`expr $1 - $3`;;
esac

echo $result

exit 0






















	















