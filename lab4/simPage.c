#include <stdio.h>
#include <stdlib.h>

int parseArguments(int argc, char *argv[]) {
  int tableSize;
  if (argc == 2 && (tableSize = atoi(argv[1]))) {
    return tableSize;
  }
  fprintf(stderr, "Wrong arguments, Pass tableSize as an argument\n");
  exit(-1);
}

int isInMemory(int pageRequest, int *pageTable, int tableSize) {
  int i;
  for (i = 0; i < tableSize; i++) {
    if (pageRequest == pageTable[i]) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int tableSize = parseArguments(argc, argv);
  int pageRequest;
  int pageTableIndex = 0;
  int numRequests = 0;
  int numMisses = 0;
  
  int *pageTable = (int *) malloc(sizeof(int)*tableSize);
  char *input = NULL;
  size_t inputAllocated = 0;
  ssize_t bytesRead;
  
  // number of hits = numRequests-numMisses
  // hit rate = hits/requests
  
  while ((bytesRead = getline(&input, &inputAllocated, stdin)) != -1) {
    pageRequest = atoi(input);
    if (pageRequest == 0) {
      continue;
    }
    numRequests++;
    if (!isInMemory(pageRequest, pageTable, tableSize)) {
      printf("Page %d caused a page fault\n", pageRequest);
      numMisses++;
      if (pageTableIndex < tableSize) {
        // stil have room in the page table
        pageTable[pageTableIndex++] = pageRequest;
      } else {
        // TODO implement a page replacement algorithm
        fprintf(stderr, "Ran out of memory. Implememnt a page replacement algorithm\n");
      }
    } // else update something in pageTable
  }
  
  printf("Hit rate: %f\n", (numRequests-numMisses)/(double)numRequests);
  
  free(input);
  free(pageTable);
  return 0;
}
