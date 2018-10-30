#!/bin/bash

if [ $# -ne 4 ]; then
  echo "Wrong usage: ./test/launch_test [d2s|d2p] [array_size] [nb_threads] [nb_tests]"
  exit
fi

./bin/generator $2

echo -n > test/output.txt

for i in $(seq 1 $4); do
  if [ "$1" == "d2s" ]; then
    ./bin/d2s < ./test/fichier_test >> test/output.txt
  else
    ./bin/d2p < ./test/fichier_test >> test/output.txt
  fi
done
