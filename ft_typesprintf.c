/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typesprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:01:44 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/08 00:03:24 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_uint(unsigned int n)
{
	int	c;

	c = 0;
	if (n >= 10)
	{
		c += ft_uint(n / 10);
		c += ft_uint(n % 10);
	}
	else
		c += ft_putchar(n + '0');
	return (c);
}

int	ft_putstr(char *s)
{
	int	i;
	int	c;

	c = 0;
	i = -1;
	if (!s)
		c += ft_putstr("(null)");
	else
	{
		while (s[++i])
			c += ft_putchar(s[i]);
	}
	return (c);
}

int	ft_putnbr(int n)
{
	int	c;

	c = 0;
	if (n == -2147483648)
	{
		c += ft_putstr("-2147483648");
		return (c);
	}
	if (n < 0)
	{
		c += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		c += ft_putnbr(n / 10);
		c += ft_putnbr(n % 10);
	}
	else
		c += ft_putchar(n + '0');
	return (c);
}

int	ft_check(unsigned long int n, int type)
{	
	int	c;

	c = 0;
	if (!n)
		c += ft_putstr("(nil)");
	else
	{
		c += ft_putstr("0x");
		c += ft_hexadec(n, type);
	}
	return (c);
}

int	ft_hexadec(unsigned long int n, int type)
{
	char	*p;
	int		c;

	c = 0;
	if (type == 'x' || type == 'p')
		p = "0123456789abcdef";
	if (type == 'X')
		p = "0123456789ABCDEF";
	if (n >= 16)
	{
		c += ft_hexadec(n / 16, type);
		c += ft_hexadec(n % 16, type);
	}
	else
		c += ft_putchar(p[n]);
	return (c);
}
