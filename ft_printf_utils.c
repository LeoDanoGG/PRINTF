/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:23:29 by legomez           #+#    #+#             */
/*   Updated: 2026/10/26 17:44:39 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(const unsigned long long ptr, char *hex, int start)
{
	int	count;

	count = 0;
	if (!ptr && start)
		return (count = print_str("(nil)"));
	if (start)
		count += print_str("0x");
	if (ptr >= 16)
	{
		count += print_ptr(ptr / 16, hex, 0);
		count += print_ptr(ptr % 16, hex, 0);
	}
	else
		count += ft_putchr(hex[ptr]);
	return (count);
}

int	print_nbr(const int n)
{
	unsigned int	nbr;
	int				count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchr('-');
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr > 9)
		count += print_nbr(nbr / 10);
	count += ft_putchr((nbr % 10) + '0');
	return (count);
}

int	print_unsigned(const unsigned int n)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	nbr = n;
	if (nbr > 9)
		count += print_nbr(nbr / 10);
	count += ft_putchr((nbr % 10) + '0');
	return (count);
}

int	print_hex(const unsigned int n, char *hex)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += print_hex(n / 16, hex);
		count += print_hex(n % 16, hex);
	}
	else
		count += ft_putchr(hex[n]);
	return (count);
}
