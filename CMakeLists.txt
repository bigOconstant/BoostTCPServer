cmake_minimum_required(VERSION 3.0)

SET(CMAKE_CXX_STANDARD 20)
project(tcpserver)

find_package(Boost 1.72 COMPONENTS program_options thread system REQUIRED)
message("finding ssl")
find_package(OpenSSL REQUIRED)
message("found ssl")
message(SSL found: ${OpenSSL_FOUND} )

message(SSL subdir: ${OPENSSL_INCLUDE_DIR} )


INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
INCLUDE_DIRECTORIES(${OPENSSL_INCLUDE_DIR})

set(RDKAFKA_BUILD_STATIC ON CACHE BOOL "")

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
target_link_libraries( tcpserver LINK_PUBLIC ${Boost_LIBRARIES} OpenSSL::SSL OpenSSL::Crypto rdkafka   rdkafka++  boost_system)
else()
message(on mac)
target_link_libraries( tcpserver LINK_PUBLIC ${Boost_LIBRARIES} OpenSSL::Crypto OpenSSL::SSL   rdkafka++  )
    endif()





install(TARGETS tcpserver RUNTIME DESTINATION bin)