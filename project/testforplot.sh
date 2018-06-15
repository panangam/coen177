#!/bin/bash
echo "tableSize, lru, fifo, sc" > sim_results.csv

sizeMin=10
sizeMax=500

for ((tableSize=sizeMin; tableSize<=sizeMax; tableSize+=10))
do
  echo $tableSize
  lru=$(cat accesses.txt | ./simQuiet -lru $tableSize)
  fifo=$(cat accesses.txt | ./simQuiet -fifo $tableSize)
  sc=$(cat accesses.txt | ./simQuiet -secondchance $tableSize)
  echo "$tableSize, $lru, $fifo, $sc" >> sim_results.csv
done
