#include "khedira_shell.h"

/**
 * main - an entry point to the app
 * Return: int
*/

int main()
{
	char myInput[MAX_ARGINPUT_SIZE];
	int mystatus = 0;

	while (1)
	{
		if (isatty(0))
		{
			khedira_prompt();
		}

		khedira_uinput(myInput, sizeof(myInput), mystatus);
		if (khedira_exit(myInput))
		{
			break;
		}

		else
		{
			khedira_exec(myInput, mystatus);
			return (mystatus);
		}
	}
	return (0);
}
