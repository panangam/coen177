#include <stdio.h>
#include <stdlib.h>

#include "FIFO.h"

int *pageQueue;
int queueSize;
int head;
int tail;

void FIFOInit(int tableSize) {
  pageQueue = (int*) malloc(tableSize*sizeof(int));
  queueSize = tableSize;
  head = 0;
  tail = 0;
}

void FIFORequest(int res) {
  return;
}

void FIFOInsert(int id) {
  pageQueue[tail] = id;
  tail = (tail+1)%queueSize;
  //printf("%d", (tail-head)%queueSize);
}

int FIFOReplace() {
  int toReplace = pageQueue[head%queueSize];
  head = (head+1)%queueSize;
  return toReplace;
}

void FIFOFree() {
  free(pageQueue);
}