#include "shell.h"

void	init_flags(t_flags *flags)
{
	flags->space = 0;
	flags->hash = 0;
	flags->plus = 0;
}

int	handle_specifier(char str, va_list *args, t_flags *flags)
{
	if (str == 'd' || str == 'i')
		return (print_number(va_arg(*args, int), flags));
	else if (str == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (str == 's')
		return (print_string(va_arg(*args, char *)));
	else if (str == '%')
		return (ft_putchar('%'));
	else if (str)
		return (ft_putchar(str));
	return (0);
}

void	loop_string(va_list *args, const char *str, int *count)
{
	t_flags	flags;

	while (*str)
	{
		if (*str != '%')
		{
			*count += ft_putchar(*str);
			str++;
		}
		else
		{
			init_flags(&flags);
			str++;
			while (check_flags(*str, &flags))
				str++;
			*count += handle_specifier(*str, args, &flags);
			if (*str)
				str++;
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	if (write (1, "", 0) == -1)
		return (-1);
	loop_string(&args, format, &count);
	va_end(args);
	return (count);
}
