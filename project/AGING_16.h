#ifndef AGING16_INCLUDE
#define AGING16_INCLUDE

void AGING16Init(int tableSize, int inMaxTick);

void AGING16Request(int id);

void AGING16Insert(int id);

int AGING16Replace();

void AGING16Free();

#endif