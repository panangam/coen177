#ifndef LRU_INCLUDE
#define LRU_INCLUDE

void LRUInit(int tableSize);

void LRURequest(int id);

void LRUInsert(int id);

int LRUReplace();

void LRUFree();

#endif