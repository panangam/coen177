#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1

int main(int argc, char* argv[]) {
	FILE *fin;        // file pointer for input
	char buffer[BUFFER_SIZE];  // string buffer
	long long i;            // iterator
	long long filesize;
	int randNum;
	char bit = 0;
	
	if (argc < 2) {
	  printf("Must supply file name as argument\n");
	  return 1;
	}
	
	fin = fopen(argv[1], "r");
	fseek(fin, 0L, SEEK_END);
	filesize = ftell(fin);
	rewind(fin);
	
  printf("filesize: %lli\n", filesize);
	
  for (i = 0; i < filesize/BUFFER_SIZE; i++) {
    if (i%10000000 == 0) printf("%lli\n", i); 
    fread(buffer, sizeof(buffer), 1, fin);
    //bit ^= buffer[0];
    randNum = rand();
    //printf("%s\n", buffer);
    //printf("%d\n", randNum);
    //printf("%li\n", filesize*randNum/RAND_MAX);
    fseek(fin, filesize*randNum/ (double) RAND_MAX, SEEK_SET);
  }
	
	printf("%x\n", bit);
	fclose(fin);
}
