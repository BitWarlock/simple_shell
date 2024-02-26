#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdarg.h>

typedef struct s_flags
{
	int	hash;
	int	plus;
	int	space;
}		t_flags;

typedef enum e_bool
{
	ifalse,
	itrue
}		t_bool;

t_bool	check_flags(char c, t_flags *flags);
void	init_flags(t_flags *flags);
int		ft_printf(const char *format, ...);
int		print_number(int n, t_flags *flags);
int		ft_putchar(char c);
int		ft_puts(char *str);
int		print_string(char *str);

#endif
