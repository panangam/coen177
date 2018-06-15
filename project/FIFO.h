#ifndef FIFO_INCLUDE
#define FIFO_INCLUDE

void FIFOInit(int tableSize);

void FIFORequest(int res);

void FIFOInsert(int id);

int FIFOReplace();

void FIFOFree();

#endif