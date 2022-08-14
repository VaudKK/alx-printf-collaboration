#include <unistd.h>
/**
 * print_hex - converts a decimal to a hexadecimal
 * @n: the number being converted
 * @isUpper: flag to check if it is upper or lower
 *
 * Return: length
 */
int print_hex(unsigned int n, int isUpper)
{
	int hexNum[64];
	char c;
	int length = 0;
	int i, v;

	for (i = 0; n > 0; )
	{
		hexNum[i++] = n % 16;
		n /= 16;
	}
	for (v = i - 1; v >= 0; v--)
	{
		if (hexNum[v] >= 0 && hexNum[v] < 10)
		{
			c = (hexNum[v] + '0');
			length += write(1, &c, sizeof(char));
		}
		else
		{
			if (isUpper == 1)
			{
				c = (hexNum[v] + 55);
			}
			else
			{
				c = (hexNum[v] + 87);
			}
			length += write(1, &c, sizeof(char));
		}
	}
	return (length);
}
/**
 * print_oct -converts a decimal to an oct
 * @num : the number being converted
 *
 * Return:length
 */
int print_oct(unsigned int num)
{
	char c;
	int length = 0;
	int octNum[64];
	int i, j;

	for (i = 0; num > 0;)
	{
		octNum[i++] = num % 8;
		num /= 8;
	}
	for (j = i - 1; j >= 0; j--)
	{
		c = octNum[j] + '0';
		length += write(1, &c, sizeof(char));
	}
	return (length);
}
