FROM ubuntu:latest
# Installo le dipendenze
RUN apt-get update && DEBIAN_FRONTEND="noninteractive" apt-get install -y \
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
    cmake \
    xauth
# Configuro xauth
COPY ./xauth_list /root/
COPY ./add_xauth.sh /root/
RUN /root/add_xauth.sh /root/xauth_list

WORKDIR /app
# Copio il progetto
COPY . .
# Buildo
RUN cmake -B ./build/ && cd ./build/ && make
# Faccio partire il comando per il progetto
WORKDIR /app/build
CMD ./evolution.out
