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
	char *string = va_arg(ap, char *);
	int len = 52;
	int i1 = 0;
	int i2;
	char pri[52] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	char seg[52] = "nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM";
	(void)params;

	if (string == NULL)
		string = "(ahyy)";
	while (string[i1])
	{
		for (i2 = 0 ; i2 < len ; i2++)
		{
			if (string[i1] == pri[i2])
			{
				_putchar(seg[i2]);
				break;
			}
		}
		if (i2 == len)
			_putchar(string[i1]);
		i1++;
	}
	return (i1);
}
