FROM ubuntu:latest

RUN apt-get update \
	&& apt-get install -y git \
						  g++ \
						  cmake \
						  make \
						  libgl-dev \
						  libvulkan-dev \
						  libgl1-mesa-dev

ADD . /upnp-chat/
WORKDIR /upnp-chat

RUN mkdir qt-dpndncy

WORKDIR /qt-dpndncy

RUN /upnp-chat/third-party/qtbase/configure -static -prefix "/usr/local/lib/Qt"

RUN	cmake --build . --parallel 4
RUN cmake --install .

WORKDIR /upnp-chat

RUN rm -R qt-dpndncy