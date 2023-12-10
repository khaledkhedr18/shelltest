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
	char *command[4];

	command[0] = "/bin/sh";
	command[1] = "-c";
	command[2] = (char *)exec_comm;
	command[3] = NULL;


	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	else if (pid == 0)
	{
		execve(command[0], exec_args, environ);
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
