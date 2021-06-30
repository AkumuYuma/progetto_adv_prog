# Progetto di fine corso di Advanced Programming Using C++
## Introduzione
Il presente codice rappresenta il progetto finale del corso di Advanced Programming using C++ (Laurea magistrale in Fisica con curriculum Particle Astroparticle Physics and Advanced Technologies UniBa). Si tratta di un algoritmo di evoluzione continua. L'ambiente è composto da veleno e cibo e i veicoli (inizialmente generati con DNA casuale) "imparano" a mangiare il cibo evitando il veleno. Ad ogni loop i veicoli hanno una piccola probabilità di clonarsi generando una copia con DNA modificato dell'1%. L'algoritmo si basa quindi sull'evidenza che i veicoli con DNA più efficiente hanno più probabilità di essere clonati (in quanto sopravvivono più a lungo). I parametri caratterizzanti il DNA dei veicoli sono quattro e rappresentano affinità (cioè quanto "forte" il veicolo è attratto) e sensibilità (cioè quanto lontano riesce a percepire) a cibo e veleno; ci aspettiamo quindi che a sistema ottimizzato si avrà grande affinità e sensibilità al cibo e bassissima sensibilità al veleno. L'affinità al veleno invece anche
dopo l'ottimizzazione non sembra avere una grande influenza.
Si parla inoltre di "evoluzione continua" in quanto non si hanno generazioni precise che si susseguono, ma ogni individuo presenta probabilità autonoma di riprodursi.

Per la renderizzazione a schermo si è utilizzata la libreria SFML.

## Utilizzo del programma
### Metodo 1: Compilare ed eseguire sulla macchina fisica
Per compilare ed eseguire il codice sulla macchina locale, è necessaria una suite di compilazione (l'ambiente di test attuale utilizza g++) ed eventualmente cmake e make e la libreria [ SFML ](https://www.sfml-dev.org/). Per installarla seguire le istruzioni
all'indirizzo [Installare SFML](https://www.sfml-dev.org/tutorials/2.5/start-linux.php).

Il workflow da eseguire per modificare l'app e ricompilarla è il seguente:
- Modificare uno o più file sorgente.
- Se è la prima volta eseguire `$ cmake -B build/` nella cartella root del progetto per creare i file di build (oppure compilare tutto con lo script [compile.sh](compile.sh)).
- Ricompilare solo i file modificati usando `$ make` all'interno della cartella build.
- Eseguire il binario generato.

### Metodo 2: Compilare ed eseguire nel docker
TODO

## Commento del codice
Commentiamo adesso brevemente le varie parti del codice. Per prima cosa si noti che il codice è stato diviso seguendo il paradigma di modularità di C++. Nella cartella src/ sono presenti i file sorgente con le definizioni di funzioni e classi
mentre nella cartella include/ sono presenti gli header con le dichiarazioni.
### Librerie e utilities
#### 1. randomTools
Libreria più semplice, contiene solo una serie di funzioni (racchiuse in un namespace) per generare numeri casuali. Inizialmente erano state implementate due diverse funzioni per la generazione di interi o float:

'''cpp
float randomTools::randomFloat(float start, float stop) {
    // Generatore random di float tra start e stop
    // :param: start -> Valore di inizio (default 0)
    // :param: stop -> Valore di fine (default 1)
    // :return: float random tra start e stop
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> distr(start, stop);
    return distr(eng);
}

int randomTools::randomInt(int start, int stop) {
    // Generatore random di interi tra start e stop.
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(start, stop);
    return distr(eng);
}
'''

Si noti che la necessità dell'utilizzo di `std::uniform_int_distribution<>()` e `std::uniform_real_distribution<>()` rende complicato l'utilizzo di un template. Comunque, in un successivo refactoring, è stato aggiunto il template:

'''cpp
template <typename T>
T randomTools::randomGenerator(const T& start, const T& stop) {
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_real_distribution<> distr(start, stop);
  return static_cast<T>( distr(eng) );
}
'''
questa soluzione riduce drasticamente la quantità di codice scritta ma non è molto efficiente, in quanto genera sempre con la distribuzione reale per float e solo successivamente fa un casting nel tipo rilevato alla chiamata.

Comunque, essendo questa funzione stata scritta successivamente, per evitare una riscrittura parziale anche degli altri source, si è scelto di adattare le funzioni `randomFload()` e `randomInt()` perchè utilizzino `randomGenerator`.

#### 2. vectorTools
Una serie di funzioni utili per la manipolazione di vettori di float (classe `sf::Vector2f` messa a disposizione da SFML) come il calcolo del modulo, la moltiplicazione per uno scalare eccetera.

#### 3. utilities


Funzioni inizialmente nel main, successivamente spostate in un modulo a parte. Interessante la funzione `creaCibo()`, che prende in ingresso la finestra su cui renderizzare, la bontà del cibo da creare e
la posizione in cui creare il cibo e restituisce un puntatore unico ad una `sf::CircleShape`, classe builtin di SFML che rappresenta un cerchio. Se la posizione non viene passata, il cibo (o veleno) viene creato
in un punto random dello schermo.

'''cpp
std::unique_ptr<sf::CircleShape> utilities::creaCibo(sf::RenderWindow &finestra, bool buono, sf::Vector2f posizione) {
  // Restituisce un puntatore unico a un cibo in una posizione random dello
  // schermo :param: buono, se vero crea un cibo, altrimenti crea un veleno
  // :param: posizione, se viene passato lo usa per creare nella posizione,
  // altrimenti crea random
  std::unique_ptr<sf::CircleShape> cibo{new sf::CircleShape{2}};

  if (posizione.x >= 0 && posizione.y >= 0) {
    cibo->setPosition(posizione.x, posizione.y);
  } else {
    cibo->setPosition(randomTools::randomFloat(0, finestra.getSize().x), randomTools::randomFloat(0, finestra.getSize().y));
  }

  if (buono) {
    cibo->setFillColor(sf::Color::Green);
  } else {
    cibo->setFillColor(sf::Color::Red);
  }

  return cibo;
}
'''
il motivo della scelta di restituire un puntatore intelligente e non una normale CircleShape sarà discusso nella parte del main. Si noti, comunque, che, pur essendo un puntatore unico, è possibile restituirlo
dalla funzione prima che vada out of scope. Questa operazione è tipica dei puntatori unici in quanto dopo l'esecuzione della funzione il point count del puntatore sarà comunque 1 (solo il puntatore a cui viene
assegnato il valore di ritorno della funzione punterà all'area di memoria contenente la CircleShape, mentre il puntatore presente nella funzione andrà out of scope e sarà distrutto).

La funzione `creaTesto()`, invece, è solo una utility per ottenere un testo in un punto dello schermo. Anche qui si utilizza una classe builtin di SFML per modellizzare il testo.

### Classe veicolo
### Main


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

Commentiamo il file di generazione del Makefile.

'''cmake
cmake_minimum_required(VERSION 3.16)
project(Evolution)

include_directories(include)
file(GLOB SORGENTI "src/*.cpp")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

add_executable(evolution.out ${SORGENTI})

target_link_libraries(evolution.out PUBLIC sfml-window sfml-graphics sfml-network sfml-system)

'''

Per prima cosa si richiede una versione minima di cmake e si da un nome al progetto, successivamente si specifica la directory contenente gli header files e i file sorgente, a questo punto si richiede
la presenza della libreria SFML, poi si compila tutto e infine si linkano le librerie all'eseguibile generato.
