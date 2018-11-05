#!/bin/bash

if [ $# -ne 5 ]; then
  echo "Wrong usage: ./test/launch_test [d2s|d2p] [nb_tests] [array_size] [limit] [nb_threads]"
  exit
fi

make clean
make generator
./bin/generator "$3"
moy=0

if [ "$1" == "d2s" ]; then
  make d2s FLAG=-DTEST
else
  make d2p FLAG="-DTEST -DNB_THREADS=$5 -DLIMIT=$4"
fi

for i in $(seq 1 $2); do
  if [ "$1" == "d2s" ]; then
    moy=$((moy+`./bin/d2s < ./test/fichier_test | tr . ,`))
  else
    moy=$((moy+`./bin/d2p < ./test/fichier_test | tr . ,`))
  fi
done

moy=$((moy/$2))
bc -l <<< "$moy/100000000"
