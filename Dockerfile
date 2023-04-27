FROM ubuntu:latest

RUN apt-get update \
	&& apt-get install -y git \
						  g++ \
						  cmake \
						  make

ADD . /upnp-chat
WORKDIR /upnp-chat

RUN mkdir qt-dpndncy
RUN cd qt-dpndncy
	
RUN ./../third-party/qtbase/configure -static -no-prefix

RUN cmake --build .

RUN cmake -B "build" -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH="../qt-dpndncy/lib/cmake"

RUN cd build
RUN cmake --build .