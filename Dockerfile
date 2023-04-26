FROM ubuntu:latest

RUN apt-get update \
	&& apt-get install -y git \
						  g++ \
						  cmake \
						  make

ADD . /upnp-chat
WORKDIR /upnp-chat

RUN chmod 100 ./build-release.sh \
	./build-release.sh
