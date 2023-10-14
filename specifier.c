#include "main.h"

/**
 * get_specifier - function that finds format
 * @s: string format
 * Return: nembers of bytes
*/

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"o", print_octal},
		{"b", print_binary},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_adress},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL},
	};
	int = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}
