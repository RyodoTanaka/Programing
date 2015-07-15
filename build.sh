#!/bin/bash

find_files=$(find .. -name "build.cmake")
command=$(echo ${find_files} | sed -e "s/ /\n/g" | sed -e "s/\.\.\//cmake -P \.\.\//g")

echo "Start to build !!"
${command}
echo "Complete to build that ..." 
echo ${find_files} | sed -e "s/ /\n/g"
