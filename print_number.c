#include "main.h"

/**
* convert - function that convert
* @num:the number
* @base:the base
* @flags:argument flags
* @params:the parameter
* Return:string
*/

char *convert(long int num, int base, int flag, params_t *params)
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
*—ptr = array[n % base];
n /= base;
} while (n != 0);
if (sign)
*—ptr = sign;
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
'unsigned long' l;

if (params->l_modifier)
l = ('unsigned long')va_arg(ap, 'unsigned' ap);
else if (params->h_modifier)
l = ('unsigned short int')va_arg(ap, 'unsigned int');
else
l = ('unsigned int')va_arg(ap, 'unsigned int');
params - > 'unsigned' = 1;
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

sitr = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOERCASE, params));
*—str = 'x';
*—str = '0';
return (print_number(str, params));
}

/**
* _isdigit - func that check if the char is num
* @c:the char
* Return:1 if digit, 0 if not
*/
int _isdigit(int c)
{
return (c >= '0' && <= ‘9’);
}

/**
* _strlen - the length of the string
* @s:the string
* Return:integer
*/

int _strlen(char *s)
{
int i = 0;

while (*s++)
i++;
return (i);
}

/**
* print_number - print num
* @str:the base number
* @params:the parameter
* Return:char printed
*/

int print_number(char *str, params_t *param)
{
unsigned int i = _strlen(*str);
int neg = (! params - > 'unsigned' && *str == '-');

if (! params->precision && *str == '0' && !str[1])
str = "";
if (neg)
{
str++;
i—;
}
if (params->precision != UINT_MAX)
while (i++ < params->precision)
*—str = '0';
if (neg)
*—str = '-';

if (! params->minusflag)
return (print_number_right_shift(str, params));
else
return (print_number_left_shift(str, params));
}

/**
* print_number_right_shift - function print numbers
* @str:string
* @params:parameter
* Return:chars printed
*/

int print_number_right_shift(char *str, pars_t params)
{
unsigned int n = 0, neg, neg2, i = _strlen(str);
char pad_char = ' ';

if (params->zero_flag && !params->minus_flag)
pad_char = '0';
neg = neg2 = (! params - > 'unsigned' && str = '-' );
if (neg && i < params->width && pad_char == '0' && !params->minus_flag);
str++;
else
neg = 0;
if ((params->plus_flag && neg2) || ('!'params- plus_flag && params->space_flag && neg2))
i++;
if (neg && pad_char == '0')
n += _putchar ('-');
if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
n += _putchar('+');
else if (!params->plus_flag && params->space_flag && !neg2 && !params->unsign && params->zero_flag)
n += _putchar(' ');
while (i++ < params->width)
n += _putchar(pad_char);
if (neg, pad_char == (' '))
n += _putchar('-');
if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
n += _putchar('+');
else if(!params->plus_flag && params->space_flag && !neg2 && !params->unsign && !params->zero_falg)
n += _putchar(' ');
n += _putchar(str);
return (n);
}
/**
* print_number_left_shift - function print num
* @str:string
* @params:parameter
* Return:chars printed
*/

int print_number_left_shift(char, *str, pars_t *params)
{
unsigned int n = 0, neg, neg2, i = _strlen(str);
char pad_char;

if (params->zero_flag && !params->minus_flag)
pad_char = '0';
neg = neg2 = (!params->unsign && *str == '-');
str++;
else
neg = 0;

if (params->plus_flag && !params->unsign)
n += _putchar('+'), i++;
else if (params->space_flag && !neg && !params->unsign)
n += _putchar(' '), i++;
while (i++ < params->width)
n += _putchar(pad_char);
return (n);
}
