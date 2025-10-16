#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_printf(const char *format, ...);
int ft_format(va_list arguments, const char format);
int ft_print_char(int c);
int ft_print_str(const char *str);
int ft_print_pointer(void *ptr);
int ft_print_nbr(int n);
int ft_print_unsigned(unsigned int n);
int ft_print_hex(unsigned int num, const char format);
int ft_print_percent(void);
