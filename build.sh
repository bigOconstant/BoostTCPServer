#!/bin/bash

mkdir build;


rm -rf libs



git submodule update --recursive --remote


cd build && rm -rf * && cmake -DCMAKE_BUILD_TYPE=Debug .. && make;

