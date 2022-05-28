/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:35:43 by acetin            #+#    #+#             */
/*   Updated: 2022/02/10 12:15:08 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (0);
	ft_strlcpy(s2, (char *)s1, i + 1);
	return (s2);
}
