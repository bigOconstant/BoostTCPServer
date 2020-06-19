# Simple TCP Server in Boost that sends messages to kafka

This repo contains a simple tcp server using C++ and Boost.

# Run with docker-compose and vscode

VSCode and the 

### Run

`docker-compose up`



### Test command with netcat

In a seperate terminal type

`netcat localhost 514`

Then type a word and it should show up in the server

### Monitor kafka bus with kaf.

`kaf consume "ingest_syslogs_netdevice" -b "localhost:9094"`
