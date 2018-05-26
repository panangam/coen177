all: sim

sim: simPage.o FIFO.o SC.o LRU.o
	gcc -o sim simPage.o FIFO.o SC.o LRU.o

simPage.o: simPage.c FIFO.h
	gcc -c simPage.c

FIFO.o: FIFO.c FIFO.h
	gcc -c FIFO.c

SC.o: SC.c SC.h
	gcc -c SC.c

LRU.o: LRU.c LRU.h
	gcc -c LRU.c

clean:
	rm *.o