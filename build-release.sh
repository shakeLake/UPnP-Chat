echo -e "Qt Build"

prefixVar="../qt-dpndncy/lib/cmake"

if [[ ! -d qt-dpndncy ]]; then
	mkdir qt-dpndncy
	cd qt-dpndncy

	if [[ "$OSTYPE" == "linux-gnu" ]]; then
		./../third-party/qtbase/configure -static -prefix "/usr/local/lib/Qt"
		cmake --build . --parallel 4
	elif [[ "$OSTYPE" == "msys" ]]; then
		./../third-party/qtbase/configure -static -platform "win32-g++" -no-prefix
		cmake --build .
	fi
fi

if [[ "$OSTYPE" == "linux-gnu" ]]; then 
	prefixVar="/usr/local/lib/Qt"
fi

echo -e "Chat Build"
cmake -B "build" -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=prefixVar

cd build
cmake --build .