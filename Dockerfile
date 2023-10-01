FROM ubuntu:latest

RUN apt-get update \
	&& apt-get install -y 	git \
				g++ \
				cmake \
				make \
				iputils-ping \
				iproute2 

ADD . /upnp_chat
WORKDIR /upnp_chat

RUN ./build.sh Release build TESTON 