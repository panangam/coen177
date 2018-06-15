#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "AGING_16.h"

#define USHRT_FRONT_BIT (USHRT_MAX-(USHRT_MAX>>1))

int maxTick;
int tick;
int timeTableSize;
unsigned short *ageTable;

void age16() {
  int i;
  for (i = 0; i < timeTableSize; i++) {
    ageTable[i] >>= 1;
  }
}

void AGING16Init(int tableSize, int inMaxTick) {
  ageTable = (unsigned short*) malloc(tableSize*sizeof(unsigned short));
  memset(ageTable, 0, tableSize*sizeof(unsigned short));
  timeTableSize = tableSize;
  maxTick = inMaxTick;
}

void AGING16Request(int id) {
  tick = (tick+1)%maxTick;
  ageTable[id] |= USHRT_FRONT_BIT; // OR with b1000000
  if (tick == 0) age16();
}

void AGING16Insert(int id) {
  tick = (tick+1)%maxTick;
  ageTable[id] |= USHRT_FRONT_BIT; // OR with b1000000
  if (tick == 0) age16();
}

int AGING16Replace() {
  int toReplace;
  int minTime = USHRT_MAX;
  int j;
  for (j = 0; j < timeTableSize; j++) {
    if (ageTable[j] < minTime) {
      minTime = ageTable[j];
      toReplace = j;
    }
  }
  ageTable[j] = USHRT_FRONT_BIT;
  return toReplace;
}

void AGING16Free() {
  free(ageTable);
}
