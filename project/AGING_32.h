#ifndef AGING32_INCLUDE
#define AGING32_INCLUDE

void AGING32Init(int tableSize, int inMaxTick);

void AGING32Request(int id);

void AGING32Insert(int id);

int AGING32Replace();

void AGING32Free();

#endif