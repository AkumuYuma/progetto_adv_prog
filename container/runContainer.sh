#!/bin/bash

echo "Produco il file xauth_list"
xauth list > xauth_list
echo "File prodotto, faccio il build del docker"
nome_immagine="progetto_cpp"
docker build -t $nome_immagine .
echo "Immagine buildata, faccio partire il docker"
docker run --rm --net=host -e DISPLAY -v /tmp/.X11-unix $nome_immagine
