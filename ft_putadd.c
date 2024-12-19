/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzafer <gzafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:06:14 by gzafer            #+#    #+#             */
/*   Updated: 2024/11/25 13:28:58 by gzafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexa(unsigned long int n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthexa(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putadd(void *ptr)
{
	int					count;
	unsigned long int	n;

	n = (unsigned long int)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthexa(n);
	return (count);
}
