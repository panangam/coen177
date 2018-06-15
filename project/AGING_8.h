#ifndef AGING8_INCLUDE
#define AGING8_INCLUDE

void AGING8Init(int tableSize, int inMaxTick);

void AGING8Request(int id);

void AGING8Insert(int id);

int AGING8Replace();

void AGING8Free();

#endif