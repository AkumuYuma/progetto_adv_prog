cmake_minimum_required(VERSION 3.16)
project(Evolution)

include_directories(include)
file(GLOB SORGENTI "src/*.cpp")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
if (NOT ${SFML_FOUND})
    message("Libreria sfml non trovata, la installo")
    execute_process(COMMAND \
                    apt-get update && DEBIAN_FRONTEND="noninteractive" apt-get install -y \
                    build-essential \
                    wget \
                    git \
                    gcc \
                    clang \
                    g++ \
                    libegl1-mesa \
                    libgl1-mesa-dev \
                    libglu1-mesa \
                    libglu1-mesa-dev \
                    libsfml-dev \
                    libgtest-dev \
                    binutils-dev \
                    libtool \
                    lua5.2 \
                    liblua5.2-dev \
                    liblua5.2-0 \
                    graphviz \
                    doxygen \
                    )
endif()

add_executable(evolution.out ${SORGENTI})

target_link_libraries(evolution.out PUBLIC sfml-window sfml-graphics sfml-network sfml-system)
