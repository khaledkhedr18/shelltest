#include "khedira_shell.h"

int	khedira_char(int c) 
{
	return write(1, &c, 1);
}

int	khedira_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return khedira_digit(-n, base) + 1;
	}
	else if (n < base)
		return khedira_char(symbols[n]);
	else
	{
		count = khedira_digit(n / base, base);
		return count + khedira_digit(n % base, base);
	}
}

int	khedira_str(char *string)
{
	int	count;

	count = 0;
	while (*string)
		count += write(1, string++, 1);
	return count;
}	

int	khedira_format(char khediraspec, va_list khediraap)
{
	int	myCount;

	myCount = 0;
	if (khediraspec == 'c')
		myCount = khedira_char(va_arg(khediraap, int));
	else if (khediraspec == 's')
		myCount = khedira_str(va_arg(khediraap, char *));
	else if (khediraspec == 'd')
		myCount = khedira_digit((long)va_arg(khediraap, int), 10);
	else if (khediraspec == 'x')
		myCount = khedira_digit((long)va_arg(khediraap, unsigned int), 16);
	else
		myCount += write(1, &khediraspec, 1);
	return myCount;
}


int	khedira(const char *myFormat, ...)
{
	va_list	khedira_ap;
	int		count;

	va_start(khedira_ap, myFormat);
	count = 0;
	while (*myFormat)
	{
		if (*myFormat == '%')
			count += khedira_format(*++myFormat, khedira_ap);
		else 
			count += write(STDOUT_FILENO, myFormat, 1);
		++myFormat;
	}
	va_end(khedira_ap);
	return count;
}