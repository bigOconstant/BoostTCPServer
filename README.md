# Simple TCP Server in Boost

This repo contains a simple tcp server using C++ and Boost.

# Run with Docker

to run this in docker build the image with the following.


### Build image

`docker build -t tcpserver .`

### Run Image

`docker run -p 14:14 tcpserver`

### Test command with netcat

In a seperate terminal type

`netcat localhost 14`

Then type a word and it should show up in the server
