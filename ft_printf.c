/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:53:59 by legomez           #+#    #+#             */
/*   Updated: 2026/10/29 09:16:10 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Prints return char */
int	print_chr(const char c)
{
	return (write(1, &c, 1));
}

/* Prints return string */
int	print_str(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
		count += print_chr(*str++);
	return (count);
}

/* Validates format */
int	ft_valid_format(const int c, const char *s)
{
	while (*s)
	{
		if (*s == (char) c)
			return (1);
		s++;
	}
	return (0);
}

/* Controls the format */
static int	ft_parser(char const *specifier, va_list arg)
{
	if (*specifier == '%')
		return (print_chr('%'));
	else if (*specifier == 'c')
		return (print_chr(va_arg(arg, int)));
	else if (*specifier == 's')
		return (print_str(va_arg(arg, char *)));
	else if (*specifier == 'd' || *specifier == 'i')
		return (print_nbr(va_arg(arg, int)));
	else if (*specifier == 'p')
		return (print_ptr(va_arg(arg, unsigned long long), HEX_LOW, 1));
	else if (*specifier == 'u')
		return (print_unsigned(va_arg(arg, unsigned int)));
	else if (*specifier == 'x')
		return (print_hex(va_arg(arg, long), HEX_LOW));
	else if (*specifier == 'X')
		return (print_hex(va_arg(arg, long), HEX_UP));
	return (0);
}

/* Check *format and args */
int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && ft_valid_format(format[1], VALID_FORMAT))
		{
			format++;
			count += ft_parser(format, args);
		}
		else if (*format == '%' && !ft_valid_format(format[1], VALID_FORMAT))
			count += print_chr(*format);
		else if (*format == '%' && !format[1])
			return (0);
		else
			count += print_chr(*format);
		format++;
	}
	va_end(args);
	return (count);
}
