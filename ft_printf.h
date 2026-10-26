/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 10:43:49 by legomez           #+#    #+#             */
/*   Updated: 2026/10/26 11:26:31 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define VALID_FORMAT "cspdiuxX%"
# define HEX_UP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"

/* printf func */
int	ft_printf(char const *format, ...);

/* Hex counter */
int	hex_count(unsigned long n);

/* Print funcs */
int	ft_putchar_int(int c, int fd);
int	print_char(int c);
int	print_str(const char *s);
int	print_int(long n);
int	print_ptr(void *p);
int	print_hex(unsigned int n, int cased);

#endif
