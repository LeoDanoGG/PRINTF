/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:36:01 by legomez           #+#    #+#             */
/*   Updated: 2026/10/23 12:31:12 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*cap_hextoa(unsigned int n, int cased)
{
	char			*c;
	int				len;
	unsigned int	num;

	num = (unsigned int) n;
	len = hex_count(n);
	c = ft_calloc((len + 1), sizeof(char));
	if (!c)
		return (free(c), NULL);
	while (len-- > 0)
	{
		if (cased)
			c[len] = HEX_UP[num % 16];
		else
			c[len] = HEX_LOW[num % 16];
		num /= 16;
	}
	return (c);
}

int	print_hex(unsigned int n, int cased)
{
	int		count;
	char	*s;

	s = cap_hextoa(n, cased);
	count = 0;
	count += write(1, s, ft_strlen(s));
	free(s);
	return (count);
}
