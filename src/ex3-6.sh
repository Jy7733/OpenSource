#!/bin/bash

if [ ! -d $1 ]
   then 
	mkdir $1
fi

cd $1
touch file0.txt
touch file1.txt
touch file2.txt
touch file3.txt
touch file4.txt

tar -cvf files.tar file0.txt file1.txt file2.txt file3.txt file4.txt

mkdir $1

mv files.tar files

cd $1

tar -xvf files.tar

exit 0





