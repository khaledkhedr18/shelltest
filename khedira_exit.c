#include "khedira_shell.h"

/**
* khedira_exit - a function that exits the shell
* Return: Void
* @excomm: the exit keyword
*/

int khedira_exit(char *excomm)
{
	return (strcmp(excomm, "exit") == 0);
}
