/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:57:11 by acetin            #+#    #+#             */
/*   Updated: 2022/03/01 13:55:37 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (strlen(s));
}

int	ft_putchr(char s)
{
	return (write(1, &s, 1));
}

int	ft_putnbr(int nb)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = nb;
	if (nb == 0)
		i = 1;
	else if (nb == -2147483648)
		i = 11;
	else if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	ft_putnbr_fd(nb);
	return (i);
}

int	print_p(unsigned long long s)
{
	int					i;
	unsigned long long	len;
	char				*set;
	char				*str;

	i = 0;
	len = s;
	while (len > 0 && ++i)
		len = len / 16;
	set = "0123456789abcdef";
	if (s == 0)
		return (write(1, "0x0", 3));
	write (1, "0x", 2);
	str = malloc(i + 1);
	len = i;
	while (s > 0)
	{
		str[--len] = set[s % 16];
		s = s / 16;
	}
	str[i] = '\0';
	ft_putstr(str);
	free (str);
	return (i + 2);
}

void	ft_putnbr_fd(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchr('-');
		ft_putchr('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchr('-');
	}
	if (nb < 10)
	{
		ft_putchr(nb + '0');
		return ;
	}
	else
	{
		ft_putnbr_fd(nb / 10);
	}
	ft_putnbr_fd(nb % 10);
}
