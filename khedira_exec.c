#include "khedira_shell.h"

/**
 * khedira_exec - a function that executes commands
 * Return: void
 * @exec_comm: the string of the command to be executed
 * @exec_args: the list of the args
*/

void khedira_exec(char *exec_comm, char *args[])
{
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(exec_comm, args);
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
