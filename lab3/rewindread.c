#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 64

int main(int argc, char* argv[]) {
	FILE *fin;        // file pointer for input
	char buffer[BUFFER_SIZE];  // string buffer
	int i;            // iterator
	long long filesize;
	
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
    fread(buffer, sizeof(buffer), 1, fin);
    rewind(fin);
  }
	
	fclose(fin);
}
