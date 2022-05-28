/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:13:15 by acetin            #+#    #+#             */
/*   Updated: 2022/02/15 15:35:52 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*nddl;

	i = 0;
	nddl = (char *)needle;
	str = (char *)haystack;
	if (!*nddl)
		return (str);
	while (i < len && str[i] != '\0')
	{
		j = 0;
		while (str[i] == nddl[j] && i < len)
		{
			i++;
			j++;
			if (nddl[j] == '\0')
				return (&str[i - j]);
		}
		i = i - j;
		i++;
	}
	return (0);
}
