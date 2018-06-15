#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FIFO.h"
#include "SC.h"
#include "LRU.h"
#include "AGING.h"
#include "AGING_8.h"
#include "AGING_16.h"
#include "AGING_32.h"

// replacement algorithms enumeration
typedef enum rep_alg {
  LRU,
  FIFO,
  SC,
  AGING,
  AGING_8,
  AGING_16,
  AGING_32,
  NONE
} REP_ALG_T;

void parseArguments(int argc, char *argv[], int *outTableSize, REP_ALG_T *outRepAlg, int* AgingMaxTick) {
  int tableSize;
  if (argc == 1) {
    fprintf(stderr, "Wrong arguments; Example: ./sim -fifo 7\n");
    exit(-1);
  }
  else if (argc == 2 && (tableSize = atoi(argv[1]))) {
    *outTableSize = tableSize;
    *outRepAlg = NONE;
    return;
  }
  else if (argc == 3) {
    if (strcmp(argv[1], "-lru") == 0) *outRepAlg = LRU;
    else if (strcmp(argv[1], "-fifo") == 0) *outRepAlg = FIFO;
    else if (strcmp(argv[1], "-sc") == 0) *outRepAlg = SC;
    else if (strcmp(argv[1], "-aging") == 0) *outRepAlg = AGING;
    else {
      fprintf(stderr, "Wrong arguments; Use -lru, -fifo, -sc, or -aging as first argument\n");
      exit(-1);
    }
    *outTableSize = atoi(argv[2]);
    return;
  }
  else if (argc == 4) {
    fprintf(stderr, "4 args\n");
    if (strcmp(argv[1], "-aging8") == 0) *outRepAlg = AGING_8;
    else if (strcmp(argv[1], "-aging16") == 0) *outRepAlg = AGING_16;
    else if (strcmp(argv[1], "-aging32") == 0) *outRepAlg = AGING_32;
    *outTableSize = atoi(argv[2]);
    *AgingMaxTick = atoi(argv[3]);
    return;
  }
  fprintf(stderr, "Wrong arguments; Pass tableSize as second argument\n");
  exit(-1);
}

int isInMemory(int pageRequest, int *pageTable, int tableSize) {
  int i;
  for (i = 0; i < tableSize; i++) {
    if (pageRequest == pageTable[i]) {
      return i;
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  int tableSize;
  int pageRequest;
  int pageTableIndex = 0;
  int numRequests = 0;
  int numMisses = 0;
  
  int *pageTable;
  char buffer[100];

  REP_ALG_T repAlg;
  void (*ReplacerRequest)(int);
  void (*ReplacerInsert)(int);
  int (*ReplacerReplace)(void);
  void (*ReplacerFree)(void);
  int toReplace;
  int searchRes;

  int AgingMaxTick;

  // parse command line arguments
  parseArguments(argc, argv, &tableSize, &repAlg, &AgingMaxTick);
  pageTable = (int *) malloc(sizeof(int)*tableSize);
  fprintf(stderr, "table size: %d\n", tableSize);

  // set appropriate function pointers for each algorithms
  if (repAlg == FIFO) {
    FIFOInit(tableSize);
    ReplacerRequest = &FIFORequest;
    ReplacerInsert = &FIFOInsert;
    ReplacerReplace = &FIFOReplace;
    ReplacerFree = &FIFOFree;
  } else if (repAlg == LRU) {
    LRUInit(tableSize);
    ReplacerRequest = &LRURequest;
    ReplacerInsert = &LRUInsert;
    ReplacerReplace = &LRUReplace;
    ReplacerFree = &LRUFree;
  } else if (repAlg == SC) {
    SCInit(tableSize);
    ReplacerRequest = &SCRequest;
    ReplacerInsert = &SCInsert;
    ReplacerReplace = &SCReplace;
    ReplacerFree = &SCFree;
  } else if (repAlg == AGING) {
    AGINGInit(tableSize);
    ReplacerRequest = &AGINGRequest;
    ReplacerInsert = &AGINGInsert;
    ReplacerReplace = &AGINGReplace;
    ReplacerFree = &AGINGFree;
  } else if (repAlg == AGING_8) {
    AGING8Init(tableSize, AgingMaxTick);
    ReplacerRequest = &AGING8Request;
    ReplacerInsert = &AGING8Insert;
    ReplacerReplace = &AGING8Replace;
    ReplacerFree = &AGING8Free;
  } else if (repAlg == AGING_16) {
    AGING16Init(tableSize, AgingMaxTick);
    ReplacerRequest = &AGING16Request;
    ReplacerInsert = &AGING16Insert;
    ReplacerReplace = &AGING16Replace;
    ReplacerFree = &AGING16Free;
  } else if (repAlg == AGING_32) {
    AGING32Init(tableSize, AgingMaxTick);
    ReplacerRequest = &AGING32Request;
    ReplacerInsert = &AGING32Insert;
    ReplacerReplace = &AGING32Replace;
    ReplacerFree = &AGING32Free;
  }


  // number of hits = numRequests-numMisses
  // hit rate = hits/requests
  
  while (fgets(buffer, sizeof(buffer), stdin)) {
    pageRequest = atoi(buffer);
    if (pageRequest == 0) { // parse request number and check for error
      continue;
    }
    numRequests++;

    searchRes = isInMemory(pageRequest, pageTable, tableSize);
    if (searchRes < 0) {
      // printf("Page %d caused a page fault.\n", pageRequest);
      numMisses++;
      if (pageTableIndex < tableSize) {
        // stil have room in the page table
        pageTable[pageTableIndex++] = pageRequest;
        (*ReplacerInsert)(pageTableIndex-1);
      } else {
        // TODO implement a page replacement algorithm
        //fprintf(stderr, "Ran out of memory. Implememnt a page replacement algorithm\n");
        toReplace = (*ReplacerReplace)();
        pageTable[toReplace] = pageRequest;
        (*ReplacerInsert)(toReplace); 
      }
    } else {
      (*ReplacerRequest)(searchRes);
    }
  }
  
  printf("Hit rate = %f\n", (numRequests-numMisses)/(double)numRequests);
  
  fprintf(stderr, "test\n");
  free(pageTable);
  fprintf(stderr, "freed page table\n");
  (*ReplacerFree)();
  return 0;
}
