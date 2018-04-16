// small command line for running another program by creating a new thread or 'exit' 

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int arcc, char *argv[])
{
	char buffer[100];	// string buffer for input
	int status;			// status from waitpid

	// main loop to receive command
	while (1) 
	{
		printf("Command: ");
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strlen(buffer)-1] = 0;
		
		// exit on 'exit' command
		if (strcmp(buffer, "exit") == 0) 
		{
			return 1;
		}
		// try to run program otherwise
		else
		{
			if (fork() != 0)
			{
				// parent
				waitpid(-1, &status, 0);
			}
			else
			{
				// child
				printf("attempting to run '%s'\n", buffer);
				execve(buffer, NULL, NULL);
				printf("error when running (program not exist?)\n");
				break;
			}
			
		}
	}
}
