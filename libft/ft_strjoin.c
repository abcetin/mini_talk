/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:55:30 by acetin            #+#    #+#             */
/*   Updated: 2022/02/11 12:56:27 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		len;
	int		s1len;
	int		s2len;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	len = s1len + s2len;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, s1len + 1);
	ft_strlcat(dest, s2, len + 1);
	return (dest);
}
