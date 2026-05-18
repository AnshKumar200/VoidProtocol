cmake_minimum_required(VERSION 3.16)

project(VoidProtocol CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(VoidProtocol ${SOURCES})

find_package(raylib REQUIRED)

target_link_libraries(VoidProtocol raylib)
