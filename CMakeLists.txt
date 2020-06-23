cmake_minimum_required(VERSION 3.0)

SET(CMAKE_CXX_STANDARD 20)
project(tcpserver)

find_package(Boost 1.72 COMPONENTS program_options thread system  REQUIRED)
#find_package(Boost REQUIRED COMPONENTS system thread)
#find_package(Boost COMPONENTS thread system)


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
add_subdirectory(libs/librdkafka)

if(UNIX AND NOT APPLE)
        set(LINUX TRUE)
    endif()
if(LINUX) 
        message(STATUS ">>> Linux")
target_link_libraries( tcpserver LINK_PUBLIC ${Boost_LIBRARIES} rdkafka  rdkafka++  boost_system)
else()
target_link_libraries( tcpserver LINK_PUBLIC ${Boost_LIBRARIES} rdkafka  rdkafka++  )
    endif()





install(TARGETS tcpserver RUNTIME DESTINATION bin)