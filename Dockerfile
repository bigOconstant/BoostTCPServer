FROM debian

RUN  apt-get update
RUN  apt-get upgrade -y

RUN apt-get install clang -y
RUN apt-get install wget -y
RUN apt install librdkafka-dev -y


# Install boost manually because we need a newer versino to match osx brew's 1.72. Debian is on a older version as of this writting
WORKDIR /boost
RUN wget -O boost_1.72_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.72.0/boost_1_72_0.tar.gz/download
RUN tar xzvf boost_1.72_0.tar.gz
WORKDIR /boost/boost_1_72_0
RUN apt-get install build-essential g++ python-dev autotools-dev libicu-dev build-essential libbz2-dev libboost-all-dev -y
RUN ./bootstrap.sh --prefix=/usr/
RUN ./b2
RUN ./b2 install


RUN apt-get install cmake -y
RUN apt-get install git -y
#RUN apt-get install librdkafka-dev -y
#RUN apt-get install librdkafka++1 -y
RUN apt-get install gdb -y


WORKDIR /app

COPY . .

RUN git submodule update --recursive --remote
WORKDIR /app/libs/librdkafka

#RUN mkdir build-dir
#WORKDIR	/app/build-dir

#RUN cmake ..

#RUN make


#ENTRYPOINT /app/build-dir/tcpserver 1026
ENTRYPOINT /bin/bash

