cmake_minimum_required(VERSION 3.0)

project(tcpserver)

add_executable(tcpserver main.cpp)

install(TARGETS tcpserver RUNTIME DESTINATION bin)
