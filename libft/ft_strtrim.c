/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:10:12 by acetin            #+#    #+#             */
/*   Updated: 2022/02/15 15:42:04 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		j;
	int		len;

	i = 0;
	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (len > i && ft_strchr(set, s1[len]))
		len--;
	ret = (char *)malloc(sizeof(char) * (len - i) + 2);
	if (!ret)
		return (0);
	j = 0;
	while (i <= len)
	{
		ret[j] = s1[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
