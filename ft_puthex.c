/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzafer <gzafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:40:07 by gzafer            #+#    #+#             */
/*   Updated: 2024/11/24 13:18:56 by gzafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	unsigned int	count;
	char			*base;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16, c);
	}
	count += ft_putchar(base[n % 16]);
	return (count);
}
