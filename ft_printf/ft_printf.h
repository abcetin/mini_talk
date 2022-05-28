/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:59:53 by acetin            #+#    #+#             */
/*   Updated: 2022/02/25 10:43:42 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct ft_prinf_vtable
{
	void	*(*func_name)(void *, int);
}	t_print;

typedef struct funcs
{
	t_print	methods;
	char	arg;
}	t_func;

typedef struct func_prototype
{
	t_func	ptstr;
	t_func	ptchr;
	t_func	ptnbr;
	t_func	pthex;
	t_func	ptu;
	t_func	ptp;
}	t_prototype;

int		ft_printf(const char *s, ...);
int		hex(unsigned int nb, int fd);
int		print_u(unsigned int nb);
int		ft_putnbr(int nb);
int		ft_putstr(char *s);
int		ft_putchr(char s);
int		print_p(unsigned long long s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int nb);
size_t	strlen(const char *str);
char	*ft_strdup(const char *s1);

#endif
