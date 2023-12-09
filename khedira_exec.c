#include "khedira_shell.h"

/**
 * khedira_exec - a function that executes commands
 * Return: void
 * @exec_comm: the string of the command to be executed
 * @exec_args: the list of the args
*/

void khedira_exec(char *exec_comm, char *exec_args[])
{
	char *myEnvp[] = {NULL};
	pid_t child_process = fork();
	char *myCommand[4];

	myCommand[0] = "/bin/sh";
	myCommand[1] = "-c";
	myCommand[2] = (char *)exec_comm;
	myCommand[3] = NULL;


	if (child_process == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_process == 0)
	{
		execve(myCommand, myCommand, myEnvp);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		int mystatus;

		if (wait(&mystatus) == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
	}
}
