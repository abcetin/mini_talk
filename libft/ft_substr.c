/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:22:49 by acetin            #+#    #+#             */
/*   Updated: 2022/02/15 15:27:03 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*src;
	size_t	i;

	i = 0;
	src = (char *)s;
	if (!s)
		return (0);
	if (start >= ft_strlen(s) || len == 0)
	{
		ret = malloc(sizeof(char));
		if (!ret)
			return (0);
		*ret = '\0';
	}
	else
	{
		if (ft_strlen(s) - start < len)
			len = ft_strlen(s) - start;
		ret = (char *)malloc(sizeof(char) * len + 1);
		if (!ret)
			return (0);
		ft_strlcpy(ret, &src[start], len + 1);
	}
	return (ret);
}
