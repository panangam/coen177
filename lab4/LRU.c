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
  printf("%d\n", time);
}

void LRUInsert(int id) {
  timeTable[id] = time++;
  printf("%d\n", time);
}

int LRUReplace() {
  int toReplace;
  int minTime = INT_MAX;
  int j;
  for (j = 0; j < timeTableSize; j++) {
    if (timeTable[j] < minTime) {
      minTime = timeTable[j];
      toReplace = j;
    }
  }
  return toReplace;
}

void LRUFree() {
  free(timeTable);
}
