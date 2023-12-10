#include "khedira_shell.h"

/**
 * main - an entry point to the app
 * Return: int
*/

int main()
{
	size_t input_len;
	int myargcount;
	char myInput[MAX_ARGINPUT_SIZE];
	char *myargs[MAX_ARGUMENTS];
	int mystatus = 0;

	while (1)
	{
		if (isatty(0))
		{
			khedira_prompt();
		}

		khedira_uinput(myInput, sizeof(myInput), mystatus);
		input_len = strlen(myInput);

		if (input_len > 0 && myInput[input_len - 1] == '\n')
		{
			myInput[input_len - 1] = '\0';
		}


		myargcount = khedira_tokenize(myInput, myargs);

		if (myargcount > 0)
		{
			if (khedira_exit(myargs[0]))
			break;

			else
			{
				mystatus = khedira_exec(myargs[0], myargs, mystatus);
			}
		}
	}
	return (0);
}
