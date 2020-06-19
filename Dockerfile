FROM debian

RUN  apt-get update
RUN  apt-get upgrade -y

RUN apt-get install clang -y

RUN apt-get install libboost-all-dev -y

RUN apt-get install cmake -y
RUN apt-get install git -y


WORKDIR /app

COPY . .

RUN mkdir build-dir
WORKDIR	/app/build-dir

RUN cmake ..

RUN make


ENTRYPOINT /app/build-dir/tcpserver 1026


