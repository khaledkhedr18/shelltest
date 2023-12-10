#include "khedira_shell.h"

/**
 * main - an entry point to the app
 * Return: int
*/

int main()
{
	/* size_t input_len; */
	char myInput[MAX_ARGINPUT_SIZE];
	/**
	* int myargcount;

	* char *myargs[MAX_ARGUMENTS];
	*/
	int mystatus = 0;

	while (1)
	{
		if (isatty(0))
		{
			khedira_prompt();
		}

		khedira_uinput(myInput, sizeof(myInput), mystatus);
		if (khedira_exit(myargs[0]))
		{
			break;
		}

		else
		{
			khedira_exec(myInput, mystatus);
		}
	}
	return (0);
}
