#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "AGING_8.h"

#define UCHAR_FRONT_BIT (UCHAR_MAX-(UCHAR_MAX>>1))

int maxTick;
int tick;
int timeTableSize;
unsigned char *ageTable;

void age8() {
  int i;
  for (i = 0; i < timeTableSize; i++) {
    ageTable[i] >>= 1;
  }
}

void AGING8Init(int tableSize, int inMaxTick) {
  ageTable = (unsigned char*) malloc(tableSize*sizeof(char));
  memset(ageTable, 0, tableSize*sizeof(char));
  timeTableSize = tableSize;
  maxTick = inMaxTick;
}

void AGING8Request(int id) {
  tick = (tick+1)%maxTick;
  ageTable[id] |= UCHAR_FRONT_BIT; // OR with b1000000
  if (tick == 0) age8();
}

void AGING8Insert(int id) {
  tick = (tick+1)%maxTick;
  ageTable[id] |= UCHAR_FRONT_BIT; // OR with b1000000
  if (tick == 0) age8();
}

int AGING8Replace() {
  int toReplace;
  int minTime = UCHAR_MAX;
  int j;
  for (j = 0; j < timeTableSize; j++) {
    if (ageTable[j] < minTime) {
      minTime = ageTable[j];
      toReplace = j;
    }
  }
  ageTable[j] = UCHAR_FRONT_BIT;
  return toReplace;
}

void AGING8Free() {
  free(ageTable);
}
