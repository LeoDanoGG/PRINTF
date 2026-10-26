/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:53:59 by legomez           #+#    #+#             */
/*   Updated: 2026/10/26 11:25:42 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Check % format and prints */
int	ft_parser(char format, va_list arg)
{
	if (format == '%' && ft_strchr(VALID_FORMAT, format))
		return (ft_putchar_int('%', 1));
	if (format == 'c')
		return (print_char(va_arg(arg, int)));
	if (format == 's')
		return (print_str(va_arg(arg, char *)));
	if (format == 'd' || format == 'i')
		return (print_int(va_arg(arg, int)));
	if (format == 'p')
		return (print_ptr(va_arg(arg, void *)));
	if (format == 'u')
		return (print_int(va_arg(arg, unsigned int)));
	if (format == 'x')
		return (print_hex(va_arg(arg, long), 0));
	if (format == 'X')
		return (print_hex(va_arg(arg, long), 1));
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
		if (*format == '%' && ft_strchr(VALID_FORMAT, *format))
		{
			format++;
			count += ft_parser(*format, args);
		}
		else if (*format == '%' && !ft_strchr(VALID_FORMAT, *format))
			format++;
		else if (*format == '%' && !format[1])
			return (0);
		else
			count += ft_putchar_int(*format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
