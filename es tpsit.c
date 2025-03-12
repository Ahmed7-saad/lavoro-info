#!/bin/bash
# Controllo che ci siano esattamente 3 argomenti
if [ $# -ne 3 ]; then
    echo "Uso: $0 <operazione> <numero1> <numero2>"
    exit 1
fi

# Prendo i parametri dalla riga di comando
operazione=$1
num1=$2
num2=$3

# Controllo che num1 e num2 siano numeri validi
if [[ ! "$num1" =~ ^-?[0-9]+$ ]] || [[ ! "$num2" =~ ^-?[0-9]+$ ]]; then
    echo "Errore: I parametri devono essere numeri interi."
    exit 2
fi

# Eseguiamo l'operazione scelta dall'utente
if [ "$operazione" = "add" ]; then
    echo "Risultato: $((num1 + num2))"
elif [ "$operazione" = "sub" ]; then
    echo "Risultato: $((num1 - num2))"
elif [ "$operazione" = "mul" ]; then
    echo "Risultato: $((num1 * num2))"
elif [ "$operazione" = "div" ]; then
    if [ "$num2" -eq 0 ]; then
        echo "Errore: divisione per zero!"
        exit 3
    fi
    echo "Risultato: $((num1 / num2))"
else
    echo "Errore: operazione non supportata (usa add, sub, mul, div)"
    exit 4
fi

