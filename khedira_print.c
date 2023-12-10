#include "khedira_shell.h"

/**
* khedira_vfprintf - a function that prints messages to the standard output
* Return: int
* @myStream: the stream of the message
* @MyFormat: the format of the message
* @MyArgs: the arguments
*/

int khedira_vfprintf(FILE *myStream, const char *MyFormat, va_list MyArgs)
{
	int result = 0;
	result = buffered_vfprintf(myStream, MyFormat, MyArgs, 0);
	return result;
}

/**
* khedira - a function that prints messages to the standard output
* Return: Void
* @myFormat: the message that we want to print.
*/

int khedira(const char *myFormat, ...)
{
	va_list khedira_args;
	va_start(khedira_args, myFormat);
	int result = vfprintf(stdout, myFormat, khedira_args);
	va_end(khedira_args);
	return result;
}