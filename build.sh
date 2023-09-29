#!/bin/bash

echo -e "UPnP chat"

prefixVar="../qt-dpndncy/lib/cmake"
qtDir="qt-dpndncy"

buildFolder="$2"
testIsOn="$3"

if [[ ! -d $qtDir ]] && [[ $testIsOn == "TESTOFF" ]]; then
	echo -e "Qt Build"

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

cmake -B $buildFolder -DCMAKE_BUILD_TYPE=$1 -DCMAKE_PREFIX_PATH=$prefixVar -DIS_TESTING=$testIsOn

cd $buildFolder
cmake --build .