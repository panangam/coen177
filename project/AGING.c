#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "AGING.h"

#define MAX_TICK 10

int timeTableSize;
unsigned char *ageTable;
int tick;

void age() {
  int i;
  for (i = 0; i < timeTableSize; i++) {
    ageTable[i] >>= 1;
  }
}

void AGINGInit(int tableSize) {
  ageTable = (unsigned char*) malloc(tableSize*sizeof(char));
  memset(ageTable, 0, tableSize*sizeof(char));
  timeTableSize = tableSize;
}

void AGINGRequest(int id) {
  tick = (tick+1)%MAX_TICK;
  ageTable[id] |= (UCHAR_MAX-(UCHAR_MAX>>1)); // OR with b1000000
  if (tick == 0) age();
}

void AGINGInsert(int id) {
  tick = (tick+1)%MAX_TICK;
  ageTable[id] |= (UCHAR_MAX-(UCHAR_MAX>>1)); // OR with b1000000
  if (tick == 0) age();
}

int AGINGReplace() {
  int toReplace;
  int minTime = UCHAR_MAX;
  int j;
  for (j = 0; j < timeTableSize; j++) {
    if (ageTable[j] < minTime) {
      minTime = ageTable[j];
      toReplace = j;
    }
  }
  ageTable[j] = (UCHAR_MAX-(UCHAR_MAX>>1));
  return toReplace;
}

void AGINGFree() {
  free(ageTable);
}
