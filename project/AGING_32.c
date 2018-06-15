#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "AGING_32.h"

#define UINT_FRONT_BIT (UINT_MAX-(UINT_MAX>>1))

int maxTick;
int tick;
int timeTableSize;
unsigned int *ageTable;

void age32() {
  int i;
  for (i = 0; i < timeTableSize; i++) {
    ageTable[i] >>= 1;
  }
}

void AGING32Init(int tableSize, int inMaxTick) {
  ageTable = (unsigned int*) malloc(tableSize*sizeof(unsigned int));
  memset(ageTable, 0, tableSize*sizeof(unsigned int));
  timeTableSize = tableSize;
  maxTick = inMaxTick;
}

void AGING32Request(int id) {
  tick = (tick+1)%maxTick;
  ageTable[id] |= UINT_FRONT_BIT; // OR with b1000000
  if (tick == 0) age32();
}

void AGING32Insert(int id) {
  tick = (tick+1)%maxTick;
  ageTable[id] |= UINT_FRONT_BIT; // OR with b1000000
  if (tick == 0) age32();
}

int AGING32Replace() {
  int toReplace;
  int minTime = UINT_MAX;
  int j;
  for (j = 0; j < timeTableSize; j++) {
    if (ageTable[j] < minTime) {
      minTime = ageTable[j];
      toReplace = j;
    }
  }
  ageTable[j] = UINT_FRONT_BIT;
  return toReplace;
}

void AGING32Free() {
  free(ageTable);
}
