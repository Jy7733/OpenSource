#!/bin/bash

myFunction() {
echo "함수 안으로 들어왔음"
eval ls "$input"
return 
}
echo "프로그램을 시작합니다."
input=$1
myFunction $input
echo "프로그램을 종료합니다."

exit 0


