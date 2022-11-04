#!/bin/bash

weight=$1
height=$2

sqr=`expr "scale=2; $height * $height" | bc`
bmi=`expr "scale=2; $weight / $sqr" | bc`

if [[ `echo "$bmi < 18.5" | bc` -eq 1 ]]
then 
	echo "저체중입니다."
else 
	if [ `echo "bmi > 23" | bc` -eq 1 ]
	then 
		echo "과체중입니다."
	else 
		echo "정상입니다."
	fi
fi











 






























exit 0 



  then
    echo "underweight"


 elif [ 1 -eq "$( (echo "$bmi > 18.5")|bc)" ] && [ 1 -eq "$( (echo "$bmi < 23")|bc)" ]
   then
      echo "normal"
   else
      echo "overweight"
fi


exit 0









