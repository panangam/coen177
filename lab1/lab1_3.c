// create 12 children by creating a symmetric processes tree
// (3 levels; each node has 3 children)

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

// Recursive function used to generate a symmetric process tree efficiently
// This procedure can create any tree with a specified depth and with all
// nodes having the same number of children
void recurse(int level, int child)
{
	int status;	// status from waitpid

	// limits that will create a tree with 12 children
	if (level <= 1 && child <= 2)
	{

		if (fork() != 0)
		{
			recurse(level, child+1);
			waitpid(-1, &status, 0);
		}
		else
		{
			// get PIDs and print
			pid_t parentPid = getppid();
			pid_t myPid = getpid();
			printf("Child  ; pid: %6d ; ppid: %6d\n", myPid, parentPid);
			recurse(level+1, 0);
		}
	}
}

int main(int arcc, char *argv[])
{
	pid_t rootPid = getpid(); // PID of the root process
	printf("Root PID: %d\n\n", rootPid);
	
	// start recursing at the root: depth 0 with 0 child
	recurse(0, 0);
}
