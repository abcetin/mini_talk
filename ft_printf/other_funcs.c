/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:46:51 by acetin            #+#    #+#             */
/*   Updated: 2022/02/27 14:50:44 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nblen(unsigned int nb, int base)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

int	hex(unsigned int nb, int fd)
{
	char	*str;
	char	*set;
	int		len;
	int		i;

	if (fd == 'x')
		set = "0123456789abcdef";
	else
		set = "0123456789ABCDEF";
	len = nblen(nb, 16);
	i = len;
	str = (char *)calloc(sizeof(char), len + 1);
	if (!str)
		return (0);
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--len] = set[nb % 16];
		nb = nb / 16;
	}
	ft_putstr(str);
	free (str);
	return (i);
}

int	print_u(unsigned int nb)
{
	int		i;
	char	*str;
	int		len;

	len = nblen(nb, 10);
	i = len;
	str = (char *)malloc(len);
	if (!str)
		return (0);
	if (nb == 0)
		ft_putchr('0');
	else
	{
		while (nb > 0)
		{
			str[--len] = ((nb % 10) + 48);
			nb = nb / 10;
		}
		str[i] = '\0';
		ft_putstr_fd(str, 1);
	}
	free(str);
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
