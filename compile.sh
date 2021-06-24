#!/bin/bash

if [[ $# != 1 ]]; then
    echo "Uso: bash compile.sh <nomeOutput>"
    exit 1
else
    echo "Compilo il progetto e linko le librerie"
    /usr/bin/g++ -o $1 librerie/randomTools/randomTools.o librerie/utilities/utilities.o librerie/vectorTools/vectorTools.o librerie/veichle/veichle.o main.cpp -lsfml-graphics -lsfml-window -lsfml-system
    exit 0
fi
