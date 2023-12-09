#include "khedira_shell.h"

/**
* khedira - a function that prints messages to the standard output
* Return: Void
* @output: the message that we want to print.
*/

void khedira(const char *output)
{
	write(STDOUT_FILENO, output, strlen(output));
}
