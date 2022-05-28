/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:52:47 by acetin            #+#    #+#             */
/*   Updated: 2022/02/15 15:10:14 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_char;
	unsigned char	*src_char;
	size_t			i;

	i = 0;
	src_char = (unsigned char *)src;
	dest_char = (unsigned char *)dest;
	if (n == 0 || dest == src)
		return (dest_char);
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest_char);
}
