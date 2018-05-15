// create 17 children by creating symmetric processes trees
// left tree: 4 nodes
// right tree: 13 nodes

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void recurse(int maxLevel, int maxChild, int level, int child)
{
	int status;	// status from waitpid

	// limits that will create a tree with 12 children
	if (level < maxLevel && child < maxChild)
	{
		if (fork() != 0)
		{
			recurse(maxLevel, maxChild, level, child+1);
			waitpid(-1, &status, 0);
		}
		else
		{
			// get PIDs and print
			pid_t parentPid = getppid();
			pid_t myPid = getpid();
			printf("Child  ; pid: %6d ; ppid: %6d\n", myPid, parentPid);
			recurse(maxLevel, maxChild, level+1, 0);
		}
	}
}

int main(int arcc, char *argv[])
{
	pid_t rootPid = getpid(); 	// PID of the root process
	int status; 				// status from waitpid	
	
	printf("Root PID: %d\n", rootPid);
	
	// create 2 children manually
	if (fork() != 0)
	{
		// root

		if (fork() != 0)
		{
			// root again
			waitpid(-1, &status, 0);
		}
		else
		{
			// second child - print out PID and parent PID
			printf("second child PID: %6d ; parent PID: %6d\n", getpid(), getppid());
			
			// create process tree with 13 nodes
			recurse(2, 3, 0, 0);
		}
		
		waitpid(-1, &status, 0);
	}
	else
	{
		// first child - print out PID and parent PID
		printf("first  child PID: %6d ; parent PID: %6d\n", getpid(), getppid());

		// create process tree with 4 nodes
		recurse(1, 3, 0, 0);
	}
}
