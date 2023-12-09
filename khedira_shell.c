#include "khedira_shell.h"

/**
 * main - an entry point to the app
 * Return: int
*/

int main()
{
	char myInput[MAX_ARGINPUT_SIZE];
	char *myargs[MAX_ARGUMENTS];

	while (1)
	{
		khedira_prompt();
		khedira_uinput(myInput, sizeof(myInput));

		size_t input_len = strlen(myInput);

		if (input_len > 0 && myInput[input_len - 1] == '\n')
		{
			myInput[input_len - 1] = '\0';
		}

		int myargcount = khedira_tokenize(myInput, myargs);

		if (myargcount > 0)
		{
			khedira_exec(myargs[0], myargs);
		}
	}
	return (0);
}
