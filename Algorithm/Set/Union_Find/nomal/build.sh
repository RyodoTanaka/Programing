#!/bin/sh

CURRENT=$(cd $(dirname $0) && pwd) 

if [ -e "$CURRENT/build" ]
then
	echo "build directory exists."
else
	echo "build directory not found."
	mkdir ${CURRENT}/build
fi

if [ -e "$CURRENT/bin" ]
then
	echo "bin directory exists."
else
	echo "bin directory not found."
	mkdir ${CURRENT}/bin
fi

cd ${CURRENT}/build
cmake ..
make -j4
cd ${CURRENT}
