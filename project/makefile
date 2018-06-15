all: sim simQuiet

sim: simPage.o FIFO.o SC.o LRU.o AGING.o
	gcc -o sim simPage.o FIFO.o SC.o LRU.o AGING.o

simQuiet: simQuiet.o FIFO.o SC.o LRU.o AGING.o AGING_8.o AGING_16.o AGING_32.o 
	gcc -o simQuiet simQuiet.o FIFO.o SC.o LRU.o AGING.o AGING_8.o AGING_16.o AGING_32.o 

simPage.o: simPage.c FIFO.h SC.h LRU.h AGING.h
	gcc -c simPage.c

simQuiet.o: simQuiet.c FIFO.h SC.h LRU.h AGING.h AGING_8.h AGING_16.h AGING_32.h
	gcc -c simQuiet.c

FIFO.o: FIFO.c FIFO.h
	gcc -c FIFO.c

SC.o: SC.c SC.h
	gcc -c SC.c

LRU.o: LRU.c LRU.h
	gcc -c LRU.c

AGING.o: AGING.c AGING.h
	gcc -c AGING.c

AGING_8.o: AGING_8.c AGING_8.h
	gcc -c AGING_8.c

AGING_16.o: AGING_16.c AGING_16.h
	gcc -c AGING_16.c
	
AGING_32.o: AGING_32.c AGING_32.h
	gcc -c AGING_32.c
	
clean:
	rm *.o
