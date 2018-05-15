// create a specified number of children processes using linear chain forking

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

// number of children to create (8 for problem 2)
#define CHILD_COUNT 8

int main(int arcc, char *argv[])
{
	int status;			// status output from waitpid
	int i;				// iterating index

	printf("Root PID: %d\n\n", getpid());

	for (i = 0; i < CHILD_COUNT; i++)
	{
		if (fork() != 0)
		{
			// parent
			pid_t parentPid = getppid();
			pid_t myPid = getpid();
			waitpid(-1, &status, 0);
			return 0;
		}
		else
		{
			// child
			pid_t parentPid = getppid();
			pid_t myPid = getpid();
			printf("Child  ; i: %d ; pid: %6d; ppid: %6d\n", i, myPid, parentPid);
		}
	}
}
