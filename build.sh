#!/bin/bash

mkdir build;


rm -rf libs



git submodule update --recursive --remote


cd build && rm -rf * && cmake -DCMAKE_BUILD_TYPE=Debug -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl -DOPENSSL_LIBRARIES=/usr/local/opt/openssl/lib  -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl .. && make;

