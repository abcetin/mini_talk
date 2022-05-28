/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:49:50 by acetin            #+#    #+#             */
/*   Updated: 2022/02/15 17:28:19 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char	*str;
	int		srclen;

	str = (char *)src;
	srclen = ft_strlen(str);
	while (srclen >= 0)
	{
		if (str[srclen] == (char)c)
			return (&str[srclen]);
		srclen = srclen - 1;
	}
	return (0);
}
