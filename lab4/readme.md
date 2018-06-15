# COEN 177 Lab 4 
*Oras Phongpanangam*

Run `make` to compile into executable file `sim`. Usage example:

`cat accesses.txt | ./sim -lru 100`

- arg 1: algorithm to use (-lru, -fifo, -secondchance)
- arg 2: table size

## Files List

### simPage.c
Main file providing command line tool functionality and arguments parsing. Page replacement algorithm is selected based on command line argument by assigning function pointers to appropriate functions provided by other modules (FIFO, SC, LRU).

### FIFO.c
Implement FIFO page replacement algorithm. Use a circular array as a queue by maintaining head and tail position, thus requiring only 1 memory allocation.

### SC.c
Implement Second Chance replacement algorithm. Almost exactly the same as FIFO, but when dequeuing a process check also if it has been referenced (maintained in another array). If referenced, process is enqueued back.

### LRU.c
Internal counter is maintained and increased each time a process is referenced. When it is, store latest reference time. When replacing, search through all pages for least recently used page to be replaced. 

### makefile
For compiling. Just run `make`.

## Results

Clearly, the hit rate increases when we use bigger page tables with higher table sizes. This makes sense, as more slots give us more opportunity to reuse the old pages. Interestingly, the performance increases almost linearly with number of pages, but at a slower rate after about 50 pages. It can be predicted that increase in performance per increase in number of pages will be less significant eventually.

FIFO generally performs slightly worse tan LRU and SC, which perform quite similarly themselves. However, at about 400 pages mark, LRU seems to be outperformed by the other 2 algorithms. Eventually, the 3 algorithms seem to perform similarly in the end at 500 pages mark, so it might just be a noise in experiments. 


![Plot](https://i.imgur.com/7noxKSW.png)