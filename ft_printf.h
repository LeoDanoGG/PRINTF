/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 10:43:49 by legomez           #+#    #+#             */
/*   Updated: 2026/10/27 17:12:54 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define VALID_FORMAT "cspdiuxX%"
# define HEX_UP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"

/* Validate x format */
int		ft_valid_format(const int c, const char *s);

/* Formats parser */
int		print_chr(const char c);
int		print_str(const char *str);
int		print_nbr(const int n);
int		print_unsigned(const unsigned int n);
int		print_ptr(const unsigned long long ptr, char *hex, int start);
int		print_hex(const unsigned int n, char *hex);

/* printf func */
int		ft_printf(char const *format, ...);

#endif
