/**
 * @file ft_printf.h
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief Include file for the ft_printf function.
 * @version 0.1
 * @date 2024-05-22 * 
 *  * @note This file is part of the MiniRT project.
 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_putcharpf(char c);
int	ft_putstrpf(char *s);
int	ft_puthexpf(unsigned long n, char format);
int	ft_putnbrpf(int n);
int	ft_putunbrpf(unsigned int n);
int	ft_putptrpf(unsigned long n);

#endif