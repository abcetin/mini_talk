/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:08:23 by acetin            #+#    #+#             */
/*   Updated: 2022/02/17 10:44:32 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest_char;
	unsigned char	*temp;
	int				i;

	i = (int)len;
	temp = (unsigned char *)src;
	dest_char = (unsigned char *)dest;
	if (dest_char > temp)
	{
		while (--i >= 0)
			dest_char[i] = temp[i];
	}
	else
		ft_memcpy(dest_char, temp, len);
	return (dest_char);
}
