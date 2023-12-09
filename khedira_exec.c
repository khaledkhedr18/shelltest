#include "khedira_shell.h"

/**
 * khedira_exec - a function that executes commands
 * Return: void
 * @exec_comm: the string of the command to be executed
 * @exec_args: the list of the args
*/

int khedira_exec(char *exec_comm, char *exec_args[], int mystatus)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	else if (pid == 0)
	{
		execve(exec_comm, exec_args, environ);
		perror(exec_args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		int childstatus = 0;

		if (wait(&mystatus) == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
		childstatus = WEXITSTATUS(mystatus);
		return (childstatus);
	}
}
