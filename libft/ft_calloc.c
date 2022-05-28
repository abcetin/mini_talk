/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:27:36 by acetin            #+#    #+#             */
/*   Updated: 2022/02/10 11:48:44 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ret;

	ret = (unsigned char *)malloc(sizeof(unsigned char) * (count * size));
	if (!ret)
		return (0);
	ft_bzero(ret, count * size);
	return (ret);
}
