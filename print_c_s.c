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
 * print_percent - prints the percent sign
 *
 * Return: lenght of the char with is 1
 */
int print_percent(void)
{
	char c = '%';

	return (write(1, &c, sizeof(char)));
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

			length += write(1, &current, sizeof(char));
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'd')
		{
			int number = va_arg(arguments, int);

			length += print_decimal(number);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			length += print_percent();
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
