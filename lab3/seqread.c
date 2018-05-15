#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1

int main(int argc, char* argv[]) {
	FILE *fin;        // file pointer for input
	char buffer[BUFFER_SIZE];  // string buffer
	int i;            // iterator
	char bit;
	
	if (argc < 2) {
	  printf("Must supply file name as argument\n");
	  return 1;
	}
	
	fin = fopen(argv[1], "r");
	
  while (fread(buffer, sizeof(buffer), 1, fin)) {
	  //bit ^= buffer[0];
  }
	
	printf("%x", bit);
	fclose(fin);
}
