#include "main.h"

/**
 * convert - function that convert
 * @num:the number
 * @base:the base
 * @flags:argument flags
 * @params:the parameter
 * Return:string
*/


char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
		n = -num;
	sign = '-';
}
	array = flags & CONVERT_LOWERCASE ? "123456789abcdef" : "123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
	*--ptr = array[n % base];
	n /= base;
	} while (n != 0);
	if (sign)
	*--ptr = sign;
	return (ptr);
}

/**
* print_unsigned - prints unsigned int number
* @ap:pointer to arguments
* @params:patameters
* Return:number of bytes
*/


int print_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
	l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(1, 10, CONVERT_UNSIGNED, params), params));
}

/**
* print_address - function that print address
* @ap:pointer to arguments
* @params:parameter
* Return:num of bytes
*/


int print _address(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
	return (_puts("(nill)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}