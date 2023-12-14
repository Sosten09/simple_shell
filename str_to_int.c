#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @x:  checked char
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char x, char *delim)
{
	while (*delim)
		if (*delim++ == x)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@y: The character to input
 *Return: 1 if  is alphabetic, 0 if not
 */

int _isalpha(int y)
{
	if ((y >= 'a' && y <= 'z') || (y >= 'A' && y <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@t: the string to convert
 *Return: 0 if null,or convert numbers
 */

int _atoi(char *t)
{
	int p, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (p = 0;  t[p] != '\0' && flag != 2; p++)
	{
		if (t[p] == '-')
			sign *= -1;

		if (t[p] >= '0' && t[p] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (t[p] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
