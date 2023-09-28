#!/bin/bash

echo -e "Qt Build"

prefixVar="../qt-dpndncy/lib/cmake"

qtDir="qt-dpndncy"

if [[ "$OSTYPE" == "linux-gnu" ]]; then
    qtDir="qt-dpndncy-linux"
    prefixVar="../qt-dpndncy-linux/lib/cmake"
fi

if [[ ! -d $qtDir ]]; then
	mkdir $qtDir
	cd $qtDir

	if [[ "$OSTYPE" == "linux-gnu" ]]; then
		./../third-party/qtbase/configure -static -prefix $prefixVar
		cmake --build . --parallel 4
	elif [[ "$OSTYPE" == "msys" ]]; then
		./../third-party/qtbase/configure -static -platform "win32-g++" -no-prefix
		cmake --build .
	fi
fi

echo -e "Chat Build"

buildFolder="$2"

testIsOn="$3"
cmake -B $buildFolder -DCMAKE_BUILD_TYPE=$1 -DCMAKE_PREFIX_PATH=$prefixVar -DIS_TESTING=$testIsOn

cd $buildFolder
cmake --build .