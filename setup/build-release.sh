echo -e "Qt Build"
mkdir qt-dpndncy
cd qt-dpndncy

if [[ "$OSTYPE" == "linux" ]]; then
	./../third-party/qtbase/configure -static
	cmake --build . --parallel
elif [[ "$OSTYPE" == "msys" ]]; then
	./../third-party/qtbase/configure.bat -static
	cmake --build .
fi

#cd ..

#echo -e "Chat Build"
#cmake -G "MinGW Makefiles" -B "build" -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH="/qt-dpndncy/lib/cmake"

#cd build
#mingw32-make