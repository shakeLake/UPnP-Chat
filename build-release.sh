echo -e "Qt Build"
mkdir qt-dpndncy
cd qt-dpndncy

if [[ "$OSTYPE" == "linux" ]]; then
	./../third-party/qtbase/configure -static -no-prefix
	cmake --build . --parallel
elif [[ "$OSTYPE" == "msys" ]]; then
	./../third-party/qtbase/configure -static -platform "win32-g++" -no-prefix
	cmake --build .
fi

echo -e "Chat Build"
cmake -B "build" -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH="../qt-dpndncy/lib/cmake"

cd build
cmake --build .