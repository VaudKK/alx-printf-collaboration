#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_binary - prints a decimal to binary
 * @number: the number being converted to binary
 *
 * Return:length
 */
int print_binary(int number)
{
	int binaryNum[64];
	int i = 0;
	int j;
	int length = 0;

	for ( ; number > 0; )
	{
		binaryNum[i++] = number % 2;
		number /= 2;
	}
	for (j = i - 1; j >= 0; j--)
	{
		char c = binaryNum[j] + '0';

		length += write(1, &c, sizeof(char));
	}
	return (length);
}

/**
 * print_unsigned_int - prints an unsigned integer
 * @number: the number to be printed
 *
 * Return: length of the number printed
 */
int print_unsigned_int(int number)
{
	if (number < 0)
		number *= -1;

	return (print_decimal(number));
}

/**
 * print_char - prints a character
 * @c: character to be printed
 *
 * Return: length of c
 */
int print_char(char c)
{
	return (write(1, &c, sizeof(char)));
}

/**
 * print_percent - prints a %
 * Return: length
 */
int print_percent(void)
{
	char c = '%';

	return (write(1, &c, sizeof(char)));
}

/**
 * print_helper_extended - extends print_helper
 * @format: the string to print
 * @arguments: the arguments
 * @i: current index
 *
 * Return: length
 */
int print_helper_extended(const char *format, va_list arguments, int *i)
{
	int length = 0;

	if (format[*i] == '%' && format[*i + 1] == 'u')
	{
		length += print_unsigned_int(va_arg(arguments, int));
		*i += 2;
	}

	return (length);
}
