/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:33:40 by acetin            #+#    #+#             */
/*   Updated: 2022/02/09 19:55:18 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t			i;
	unsigned char	*ptr_char;

	i = 0;
	ptr_char = (unsigned char *)ptr;
	while (i < n)
	{
		ptr_char[i] = (unsigned char)x;
		i++;
	}
	return (ptr_char);
}
