#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "LRU.h"

int timeTableSize;
int *timeTable;
int time;

void LRUInit(int tableSize) {
  timeTable = (int*) malloc(tableSize*sizeof(int));
  memset(timeTable, INT_MAX , tableSize*sizeof(int));
  timeTableSize = tableSize;
  time = 0;
}

void LRURequest(int id) {
  timeTable[id] = time++;
}

void LRUInsert(int id) {
  timeTable[id] = time++;
}

int LRUReplace() {
  int toReplace;
  int minTime = INT_MAX;
  int i;
  for (i = 0; i < timeTableSize; i++) {
    if (timeTable[i] < minTime) {
      minTime = timeTable[i];
      toReplace = i;
    }
  }
  return toReplace;
}

void LRUFree() {
  free(timeTable);
}
