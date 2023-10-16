#include "main.h"


/**
 * print_from_to - function to print rang of chars
 * @start:starting the adress
 * @stop:stopping the adress
 * @except:except adress
 * Return:number of bytes
 */


int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
{
	if (start != except)
		sum += _putchar(*start);
	start++;
}
	return (sum);
}


/**
* print_rev - function that print string in reverse
* @ap:the string
* @params:the parameters struct
* Return:number of bytes
*/


int print_rev(va_list ap, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
	str--;
	for (; len > 0; len--, str--)
		sum += _putchar(*str);
	}
	return (sum);
}


/**
 * print_rot13 - function that print string in rot13
 * @ap:parameter's
 * @params:params struct
 * Return:number of bytes
 */


int print_rot13(va_list ap, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
	if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
	{
		index = a[i] - 65;
		count += _putchar(arr[index]);
	}
	else
	count += _putchar(a[i]);
	i++;
	}
	return (count);
}