/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:35:22 by acetin            #+#    #+#             */
/*   Updated: 2022/02/17 16:10:49 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src1;
	const unsigned char	*src2;

	src1 = (const unsigned char *)s1;
	src2 = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*src1++ != *src2++)
			return ((int)(src1[-1] - src2[-1]));
	}
	return (0);
}
