/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:54:16 by acetin            #+#    #+#             */
/*   Updated: 2022/03/01 13:51:51 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static t_func	*ft_funcs(void)
{
	t_func		*f;
	t_prototype	t;

	t.ptstr = (t_func){{(void *)ft_putstr}, 's'};
	t.ptchr = (t_func){{(void *)ft_putchr}, 'c'};
	t.ptnbr = (t_func){{(void *)ft_putnbr}, 'd'};
	t.pthex = (t_func){{(void *)hex}, 'X'};
	t.ptu = (t_func){{(void *)print_u}, 'u'};
	t.ptp = (t_func){{(void *)print_p}, 'p'};
	f = malloc(sizeof(t_func) * 6);
	f[0] = t.ptchr;
	f[1] = t.ptstr;
	f[2] = t.ptnbr;
	f[3] = t.pthex;
	f[4] = t.ptu;
	f[5] = t.ptp;
	return (f);
}

static int	choose(char s, va_list str)
{
	t_func		*f;
	int			i;
	int			ret;

	f = ft_funcs();
	i = -1;
	ret = 0;
	if (s == 'i')
		s = 'd';
	if (s == 'x')
		f[3].arg = 'x';
	while (++i < 6)
	{
		if (f[i].arg == s)
		{
			ret = ((int)f[i].methods.func_name(va_arg(str, void *), s));
			break ;
		}
	}
	if (f[i].arg != s)
		ret = write(1, &s, 1);
	free(f);
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += choose(s[i], ap);
		}
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return ((count));
}
