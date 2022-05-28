/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:50:52 by acetin            #+#    #+#             */
/*   Updated: 2022/02/15 15:31:44 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rev_string(char *s)
{
	int		i;
	int		len;
	char	ret;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		ret = s[len - 1];
		s[len - 1] = s[i];
		s[i] = ret;
		len--;
		i++;
	}
	return (s);
}

static int	numberlen(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (9);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*putnbr(char *ret, int nb)
{
	int	i;
	int	len;

	i = 0;
	len = numberlen(nb);
	if (nb == -2147483648)
	{
		ret[len + 1] = '-';
		ret[len] = '2';
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb *= -1;
		ret[len] = '-';
	}
	while (nb > 0)
	{
		ret[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	ret = rev_string(ret);
	return (ret);
}

char	*ft_itoa(int nb)
{
	char	*ret;
	int		numblen;

	if (nb == 0)
		return (ft_strdup("0"));
	numblen = numberlen(nb);
	if (nb < 0)
		numblen = numblen + 1;
	ret = (char *)malloc((sizeof(char) * numblen) + 1);
	if (!ret)
		return (0);
	ret[numblen] = '\0';
	ret = putnbr(ret, nb);
	return (ret);
}
