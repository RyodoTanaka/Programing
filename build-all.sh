#!/bin/sh

find_files=$(find ./ -name "build.sh")
file_num=$(find ./ -name "build.sh" | wc -l)

if [ -z "$1" ]; then
	echo " ----- Start to build ----- "
	for (( i = 0 ; i < $file_num ; i++ )) {
		$( echo ${find_files} | cut -d' ' -f$((i+1)) )
	}
	echo " ----- Build List ----- " 
	echo ${find_files} | sed -e "s/ /\n/g" | sed -e "s/build\.sh//g"	
elif [ $1 = "clean" ]; then
	remove_files_build=$(find ./ -name "build")
	remove_files_bin=$(find ./ -name "bin")
	rm -rf ${remove_files_build}
	rm -rf ${remove_files_bin}
	echo " ----- Removed List ----- "
	echo ${remove_files_build} | sed -e "s/ /\n/g" | sed -e "s/build/build \& bin/g"
else
	echo " !!!! Error Unexpected option. Use \"clean\" option. !!!! "
fi



