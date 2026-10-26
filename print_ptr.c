/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:24:00 by legomez           #+#    #+#             */
/*   Updated: 2026/10/23 10:19:39 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Hex div count */
int	hex_count(unsigned long n)
{
	long	num;

	if (n == 0)
		return (1);
	num = 0;
	while (n > 0)
	{
		n /= 16;
		num++;
	}
	return (num);
}

/* Hex to ASCII */
static char	*hextoa(void *p)
{
	char			*c;
	int				len;
	unsigned long	num;

	num = (unsigned long) p;
	len = hex_count((unsigned long) p);
	c = ft_calloc((len + 1), sizeof(char));
	if (!c)
		return (free(c), NULL);
	while (len-- > 0)
	{
		c[len] = HEX_LOW[num % 16];
		num /= 16;
	}
	return (c);
}

/* Print pointers */
int	print_ptr(void *p)
{
	int			count;
	size_t		hex;
	char		*s;

	if (!p)
		return (print_str("(nil)"));
	s = hextoa(p);
	count = 0;
	hex = (unsigned long) p;
	count += write(1, "0x", 2);
	count += write(1, s, ft_strlen(s));
	free(s);
	return (count);
}
