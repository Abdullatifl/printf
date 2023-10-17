#include "main.h"


/**
 * get_precision - Calculates the precision for printing
 * @p:pointer to the format string
 * @params: pointer to a parameters structure
 * @ap: pointer to a variable argument list
 * Return: pointer
 */

char *get_precision(char *p, params_t *params, va_list ap)
{
	int x = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		x = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			x = x * 10 + (*p++ - '0');
	}
	params->precision = x;
	return (p);
}
