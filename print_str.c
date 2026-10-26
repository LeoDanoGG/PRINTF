/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:08:38 by legomez           #+#    #+#             */
/*   Updated: 2026/10/22 18:07:36 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Prints char (and %) */
int	ft_putchar_int(int c, int fd)
{
	return (write(fd, &c, 1));
}

/* Print chars */
int	print_char(int c)
{
	int	count;

	count = 0;
	count += ft_putchar_int(c, 1);
	return (count);
}

/* Print strings */
int	print_str(const char *s)
{
	int	count;

	if (!s)
		s = "(null)";
	count = 0;
	count += write(1, s, ft_strlen(s));
	return (count);
}
