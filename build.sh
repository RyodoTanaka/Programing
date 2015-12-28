#!/bin/bash
find_files=$(find . -name "build.cmake")
command=$(echo ${find_files} | sed -e "s/ /\n/g" | sed -e "s/\.\//cmake -P \.\//g")

if [ -z "$1" ]; then
	echo "Start to build !!"
	${command}
	echo "Compiled List" 
	echo ${find_files} | sed -e "s/ /\n/g"	
elif [ $1 = "clean" ]; then
	remove_files=$(find . -name "build")
	rm -rf ${remove_files}
	echo "Removed"
	echo ${remove_files}
else
	echo "Uncorrect command..."
fi



