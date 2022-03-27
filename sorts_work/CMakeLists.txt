cmake_minimum_required(VERSION 3.10.2)

project(programa_gr5)

#comment
include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB SOURCES "src/*.c")

add_executable(programa_gr5.bin ${SOURCES})