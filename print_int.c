/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:56:55 by legomez           #+#    #+#             */
/*   Updated: 2026/10/23 09:56:41 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* long div count */
static int	ft_lcount(long n1)
{
	long	num;

	num = 0;
	if (n1 != 0)
	{
		if (n1 < 0)
			n1 = -n1;
		while (n1 > 0)
		{
			n1 /= 10;
			num++;
		}
		return (num);
	}
	else
		return (1);
	return (num);
}

/* long control */
static char	*ft_ltoa(long n)
{
	char	*c;
	long	num;
	int		neg;
	long	n1;

	neg = 0;
	n1 = n;
	if (n1 < 0)
	{
		n1 = -n1;
		neg++;
	}
	num = ft_lcount((long) n);
	c = (char *) ft_calloc((num + neg + 1), sizeof(char));
	if (!c)
		return (free(c), NULL);
	if (neg)
		c[0] = '-';
	while (num-- > 0)
	{
		c[num + neg] = (n1 % 10 + '0');
		n1 /= 10;
	}
	return (c);
}

/* Print integers */
int	print_int(long n)
{
	int		count;
	char	*s;

	s = ft_ltoa(n);
	count = 0;
	count += write(1, s, ft_strlen(s));
	free(s);
	return (count);
}
