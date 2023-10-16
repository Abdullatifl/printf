#include "main.h"

/**
 * print_char - func that print chars
 * @ap: poiter to arguments
 * @params: parameter
 * Return: number chars printed
*/

int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - func print integer num
 * @ap: pointer to argumets
 * @params: paramseter
 * Return: int num
*/
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(1, 10, 0, params), params));
}

/**
 * print_string - func that print string
 * @ap: pointer to arg
 * @params: parameter
 * Return: num of chars
*/

int print_string(va_list ap, params_t *params)
{
		char *str = va_arg(ap, char *), pad_char = ' ';
		unsigned int pad = 0, sum = 0, i = 0, j;

		(void)params;
		switch ((int)(!str))
		case 1:
			str = NULL_STRING;

		j = pad = _strlen(str);
		if (params->precision < pad)
			j = pad = params->precision;

		if (params->minus_flag)
		{
			if (params->precision != UINT_MAX)
				for (i = 0; i < pad; i++)
					sum += _putchar(*str++);
			else
				sum += _puts(str);
		}
		while (j++ < params->width)
			sum += _putchar(pad_char);
		if (!params->minus_flag)
		{
			if (params->precision != UNIT_MAX)
				for (i = 0; i < pad; i++)
					sum += _putchar(*str++);
			else
				sum += _puts(str);
		}
		return (sum);
}
