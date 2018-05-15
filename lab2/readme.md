# COEN 177 Lab 2
*Oras Phongpanangam*

Made changes to Minix kernel source code to produce the following effects
1. Add custom text ("...edited by Oras...") to the start up banner text when booting
2. Add randomness to process selection process to make booting slower (~7 seconds -> ~1 minute)

## Changed Files

- `main.c`

Added some text to `announce()` function which prints the banner text when booting.

- `proc.c`

Inside the function `pick_proc()`, added these code inside the for-loop iterating over queues (q):

```c
rand_num = rand();
if (q > 5 && rand_num < 16000) {
	continue;
}
```
That is, if we are considering priority of greater than 5, and if generated random number is less than 16000 (about 50% chance), we defer this priority level and attempt to get a process with less priority. So we have this probability distribution:

- 50% chance that we defer level 6
- 25% chance that we defer level 7 as well
- 12.5% chance that we defer level 8 as well
- ...and so on

So processes with higher priority will have higher chance to be run, but processes with low priority may be selected as well. The result is that the boot time increases from ~7 seconds to ~1 minute.

## Testing

Simply booting up the modified Minix system will produce all the desired effects (modified banner, increased boot time).
