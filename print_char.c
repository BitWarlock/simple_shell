#include "shell.h"

int	ft_putchar(char h)
{
	write (1, &h, 1);
	return (1);
}

int	ft_puts(char *str)
{
	int	count;

	count = -1;
	while (str[++count])
		ft_putchar(str[count]);
	return (count);
}

int	print_string(char *str)
{
	if (!str)
		str = "(null)";
	return (ft_puts(str));
}
