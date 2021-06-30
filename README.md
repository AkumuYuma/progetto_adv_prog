# Progetto di fine corso di Advanced Programming Using C++
## Introduzione
Il presente codice rappresenta il progetto finale del corso di Advanced Programming using C++ (Laurea magistrale in Fisica con curriculum Particle Astroparticle Physics and Advanced Technologies UniBa). Si tratta di un algoritmo di evoluzione continua. L'ambiente è composto da veleno e cibo e i veicoli (inizialmente generati con DNA casuale) "imparano" a mangiare il cibo evitando il veleno. Ad ogni loop i veicoli hanno una piccola probabilità di clonarsi generando una copia con DNA modificato dell'1%. L'algoritmo si basa quindi sull'evidenza che i veicoli con DNA più efficiente hanno più probabilità di essere clonati (in quanto sopravvivono più a lungo). I parametri caratterizzanti il DNA dei veicoli sono quattro e rappresentano affinità (cioè quanto "forte" il veicolo è attratto) e sensibilità (cioè quanto lontano riesce a percepire) a cibo e veleno; ci aspettiamo quindi che a sistema ottimizzato si avrà grande affinità e sensibilità al cibo e bassissima sensibilità al veleno. L'affinità al veleno invece anche
dopo l'ottimizzazione non sembra avere una grande influenza.
Si parla inoltre di "evoluzione continua" in quanto non si hanno generazioni precise che si susseguono, ma ogni individuo presenta probabilità autonoma di riprodursi.

Per la renderizzazione a schermo si è utilizzata la libreria SFML.

## Utilizzo del programma

## Commento del codice
## Nota sulla compilazione
Il progetto è stato diviso in moduli che sono stati compilati separatamente e successivamente linkati al main tramite l'uso del linker. In prima approssimazione si è scritto un brevissimo script in bash [compile.sh](compile.sh)
'''bash
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
'''
Lo script compila i file sorgente separatamente ponendoli nella cartella *binari* e successivamente compila il main.cpp linkando gli object file e le librerie sfml.

Successivamente si è optato per una soluzione più automatica utilizzando il software CMake che produce automaticamente il Makefile. Il vantaggio di questo approccio è la semplicità nella gestione,
infatti, una volta prodotto il Makefile, il comando make procederà alla compilazione e al linking delle librerie. Interessante notare che utilizzando make, solamente i file sorgente modificati vengono ricompilati, diversamente dallo script sopra in cui ad ogni esecuzione viene ricompilato tutto il codice, rendendo il processo inutilmente lento e poco scalabile.

Commentiamo il file di generazione del Makefile

'''cmake
cmake_minimum_required(VERSION 3.16)
project(Evolution)

include_directories(include)
file(GLOB SORGENTI "src/*.cpp")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

add_executable(evolution.out ${SORGENTI})

target_link_libraries(evolution.out PUBLIC sfml-window sfml-graphics sfml-network sfml-system)

'''

# progetto_adv_prog
Progetto il corso di advanced programming using C++. Algoritmo genetico di evoluzione continua. Renderizzato con la libreria SFML
