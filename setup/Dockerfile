FROM ubuntu:latest

RUN apt-get update \
	&& apt-get install -y	git \
							g++ \
							cmake \
							make

ADD . /upnp_chat
WORKDIR /upnp_chat

# starts Qt configure file ( no prefix )
# builds Qt libraries to qt-dpndcy ( 99999 years to build :\ :\ :\ :\ )
RUN cd qt-dpndncy \
	./../third-party/qtbase/configure -static -no-prefix

RUN cmake --build . \
	cd ..

RUN cmake -G "Unix Makefiles" -B "build" -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH="/qt-dpndncy/lib/cmake"

RUN cd build \
	make
