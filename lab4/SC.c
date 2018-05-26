#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SC.h"

int *pageQueue;
int queueSize;
int head;
int tail;
int *referenced;

void SCInit(int tableSize) {
  pageQueue = (int*) malloc(tableSize*sizeof(int));
  referenced = (int*) malloc(tableSize*sizeof(int));
  memset(referenced, 1 , tableSize*sizeof(int));
  queueSize = tableSize;
  head = 0;
  tail = 0;
}

void SCRequest(int id) {
  referenced[id] = 1;
}

void SCInsert(int id) {
  pageQueue[tail] = id;
  tail = (tail+1)%queueSize;
  referenced[id] = 0;
  //printf("%d", (tail-head)%queueSize);
}

int SCReplace() {
  int toReplace;
  while (1) {
    if (referenced[pageQueue[head]]) {
      pageQueue[tail] = pageQueue[head];
      referenced[pageQueue[head]] = 0;
      tail = (tail+1)%queueSize;
      head = (head+1)%queueSize;
    } else {
      toReplace = pageQueue[head];
      head = (head+1)%queueSize;
      return toReplace;
    }
  }
}

void SCFree() {
  free(pageQueue);
  free(referenced);
}
