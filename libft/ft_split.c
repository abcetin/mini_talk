/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <abdullah@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:21:29 by acetin            #+#    #+#             */
/*   Updated: 2022/02/12 17:19:28 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_counter(char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

static char	**split_string(char **ret, char *s, char c)
{
	size_t	j;
	size_t	k;
	size_t	i;

	i = 0;
	j = 0;
	k = 0;
	while (j < char_counter((char *)s, c))
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[k] != c && s[k] != '\0')
			k++;
		ret[j] = ft_substr((char *)s, i, (k - i));
		i = k;
		j++;
	}
	ret[j] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret1;

	if (!s)
		return (0);
	ret1 = (char **)malloc(sizeof(char *) * (char_counter((char *)s, c) + 1));
	if (!ret1)
		return (0);
	ret1 = split_string(ret1, (char *)s, c);
	return (ret1);
}
