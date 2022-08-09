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
	return (i + 1);
}
/**
 * print_char_str - prints characters and strings to std out put
 * @format: the specified string format
 * @arguments: string var args
 *
 * Return: length of the string printed
 */
int print_char_str(const char *format, va_list arguments)
{
	int i = 0;
	int length = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 's')
		{
			char *current = va_arg(arguments, char *);
			int len = write(1, current, sizeof(char) * _strlen(current));

			i += 2;
			length += len;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			char current = va_arg(arguments, int);
			int len = write(1, &current, sizeof(char));

			length += len;
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
	result = print_char_str(format, arguments);
	va_end(arguments);
	return (result);
}
