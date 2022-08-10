#include <unistd.h>
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
 * print_percent - prints a %
 * Return: length
 */
int print_percent(void)
{
	char c = '%';

	return (write(1, &c, sizeof(char)));
}
