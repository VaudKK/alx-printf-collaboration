#include <unistd.h>
#include <stdarg.h>

/**
 * _strlen - finds the length of a string
 * @format : the string
 *
 * Return: returns the length of the string
 */
int _strlen(char *format)
{
	int i = 0;

	while (format[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * print_string - prints a string to the std out
 * @str: the string to be printed
 *
 * Return: length of the string printed
 */
int print_string(char *str)
{
	return (write(1, str, sizeof(char) * _strlen(str)));
}

/**
 * print_decimal - prints numbers
 * @number: the number to be printed
 *
 * Return: the length of the number
 */
int print_decimal(int number)
{
	int len = 0;

	if (number < 0)
	{
		char c;

		number *= -1;

		c = '-';
		len += write(1, &c, sizeof(char));
	}

	if (number != 0)
	{
		char c;

		print_decimal(number / 10);
		c = (number % 10) + '0';

		len += write(1, &c, sizeof(char));
	}
	return (len);
}

/**
 * print_helper - prints characters and strings to std out put
 * @format: the specified string format
 * @arguments: string var args
 *
 * Return: length of the string printed
 */
int print_helper(const char *format, va_list arguments)
{
	int i = 0;
	int length = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 's')
		{
			length += print_string(va_arg(arguments, char *));
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			char c = va_arg(arguments, int);

			length += write(1, &c, sizeof(char));
			i += 2;
		}
		else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			length += print_decimal(va_arg(arguments, int));
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			char c = '%';

			length += write(1, &c, sizeof(char));
			i += 2;
		}
		else
		{
			write(1, format + i, 1);
			i++;
			length++;
		}
	}
	return (length);
}

/**
 * _printf - mimics printf of the standard c library
 * @format: the format of the input string
 *
 * Return: length of the output string
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int result;

	va_start(arguments, format);
	result = print_helper(format, arguments);
	va_end(arguments);
	return (result);
}
