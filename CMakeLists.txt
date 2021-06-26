cmake_minimum_required(VERSION 3.16)
project(Evolution)

include_directories(include)
file(GLOB SORGENTI "src/*.cpp")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

add_executable(evolution.out ${SORGENTI})

target_link_libraries(evolution.out sfml-window sfml-graphics sfml-network sfml-system)
