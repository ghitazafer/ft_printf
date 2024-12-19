/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzafer <gzafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:11:49 by gzafer            #+#    #+#             */
/*   Updated: 2024/11/25 17:20:44 by gzafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), c);
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 'p')
		count += ft_putadd(va_arg(ap, void *));
	else if (c == 'u')
		count += ft_putunbr(va_arg(ap, unsigned int));
	else if (c == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	ap;

	count = 0;
	i = 0;
	if (write (1, "", 0) == -1)
		return (-1);
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			count += ft_specifier(str[i + 1], ap);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
