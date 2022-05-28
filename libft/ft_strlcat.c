/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 09:59:12 by acetin            #+#    #+#             */
/*   Updated: 2022/02/09 19:50:38 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize <= dlen)
		return (dstsize + slen);
	i = 0;
	while (src[i] != '\0' && dlen < dstsize - 1)
	{
		dst[dlen] = src[i];
		dlen++;
		i++;
	}
	dst[dlen] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
