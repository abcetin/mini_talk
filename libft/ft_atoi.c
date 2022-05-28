/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:54:04 by acetin            #+#    #+#             */
/*   Updated: 2022/02/12 17:46:37 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	ret;
	int				isnegative;

	i = 0;
	ret = 0;
	isnegative = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		isnegative *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_isprint(str[i]) == 0)
			return (0);
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	if (ret > 2147483647 && isnegative != -1)
		return (-1);
	if (ret > 2147483648 && isnegative == -1)
		return (0);
	return (ret * isnegative);
}
