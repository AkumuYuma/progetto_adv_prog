#!/bin/bash

# Aggiunge ogni riga del file passato in ingresso al xauth
while IFS='' read -r LINE || [ -n "${LINE}" ]; do
    xauth add ${LINE}
done < ./$1
