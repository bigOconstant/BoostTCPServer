cmake_minimum_required(VERSION 3.0)

SET(CMAKE_CXX_STANDARD 20)
project(tcpserver)

find_package(Boost 1.67 COMPONENTS program_options REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
set( project_sources
   main.cpp
   VariableService.cpp
   tcp_connection.cpp
   tcp_server.cpp
)


add_executable(${PROJECT_NAME}
  ${project_sources}
)

target_link_libraries( tcpserver  LINK_PUBLIC ${Boost_LIBRARIES} -lrdkafka++)



install(TARGETS tcpserver RUNTIME DESTINATION bin)
