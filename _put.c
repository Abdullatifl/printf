#include "main.h"

/**
 * _puts - function that print a string
 * @str:string that will printed
 * Return:void
 */

int _puts(char *str)
{
char *a = str;

while (*str)
_putchar(*str++);
return (str - a);
}

/**
 * _putchar - function that print by character
 * @c:the character that will printed
 * Return:1 in sucess 0 on error
 */

int _putchar(int c)
{
static int i;
static char buf[OUTPUT_BUF_SIZE];

if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
