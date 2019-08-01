cmake_minimum_required(VERSION 3.13)
project(BLOCKCHAIN)

set(CMAKE_CXX_STANDARD 14)

add_executable(BLOCKCHAIN main.cpp)

include_directories(cryptopp/general)