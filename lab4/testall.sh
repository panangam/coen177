make
cat PagingLabResources/accesses.txt | ./sim -fifo 100 > fifo100out.txt
cat PagingLabResources/accesses.txt | ./sim -secondchance 100 > sc100out.txt
cat PagingLabResources/accesses.txt | ./sim -lru 100 > lru100out.txt
diff PagingLabResources/fifo100Output fifo100out.txt
diff PagingLabResources/sc100Output sc100out.txt
diff PagingLabResources/lru100Output lru100out.txt
