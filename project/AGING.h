#ifndef AGING_INCLUDE
#define AGING_INCLUDE

void AGINGInit(int tableSize);

void AGINGRequest(int id);

void AGINGInsert(int id);

int AGINGReplace();

void AGINGFree();

#endif