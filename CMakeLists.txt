cmake_minimum_required(VERSION 3.12)
project(MeshUnwrapper VERSION 0.1.0)

include_directories(include/)

file(GLOB HEADERS "include/*.h")
file(GLOB SOURCES "src/*.cpp")
add_library(MeshUnwrapper SHARED ${SOURCES} ${HEADERS})