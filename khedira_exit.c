#include "khedira_shell.h"

/**
 * khedira_exit - a function that exits the shell
 * Return: int
 * @excomm: the command
*/

int khedira_exit(char *excomm)
{
	return (strcmp(excomm, "exit") == 0);
}
