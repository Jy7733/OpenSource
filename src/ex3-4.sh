#!/bin/bash

echo "리눅스가 재미있나요? (yes/no)"
read input
case $input in 
	y | Y | yes )
		echo "yes" ;;
	n | N | no )
		echo "no" ;;
	* )
		echo "yes or no로 입력해주세요."
		exit 1 ;;
esac;
exit 0

