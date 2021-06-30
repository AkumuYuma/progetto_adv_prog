#!/bin/bash

if [[ $# != 1 ]]; then
    echo "Uso: bash compile.sh <nomeOutput>"
    exit 1
else
    echo "Compilo il progetto e linko le librerie"
    cd src
    for source in ./*; do
        if [[ $source != "./main.cpp" ]]; then
            echo "Compilo il file "$source
            /usr/bin/g++ -c $source -o "../binari/"$source".o"
        fi
    done
    echo "File compilati, linko le librerie sfml"
    cd ..
    /usr/bin/g++ -o ./binari/$1 ./binari/randomTools.cpp.o ./binari/utilities.cpp.o ./binari/vectorTools.cpp.o ./binari/veichle.cpp.o ./src/main.cpp -lsfml-graphics -lsfml-window -lsfml-system
    exit 0
fi
