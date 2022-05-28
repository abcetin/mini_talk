/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:24:58 by acetin            #+#    #+#             */
/*   Updated: 2022/04/14 16:24:59 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static int	g_sent;

char	*palette(char *str)
{
	char	*pid;
	char	*ret;
	int		i;
	int		j;

	i = -1;
	j = -1;
	pid = ft_itoa(getpid());
	ret = (char *)calloc(sizeof(char), ft_strlen(pid) + ft_strlen(str) + 3);
	while (str[++j])
		ret[++i] = str[j];
	j = -1;
	ret[++i] = ',';
	while (pid[++j])
		ret[++i] = pid[j];
	ret[++i] = '.';
	return (ret);
}

void	send_signal(int pid, char *msg)
{
	unsigned int	i;
	int				j;
	unsigned int	bin;

	i = 0;
	j = 0;
	while (msg[i] != '\0')
	{
		bin = 1 << 7;
		while (j < 8)
		{
			if (msg[i] & bin)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
			bin >>= 1;
			j++;
		}
		i++;
		j = 0;
	}
}

void	handler(int sig)
{
	g_sent = sig;
	ft_printf("Mesaj İletildi");
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("[PID] [MESSAGE]");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, handler);
	send_signal(ft_atoi(av[1]), palette(av[2]));
	if (g_sent == 0)
	{
		ft_printf("Mesaj İletilemedi");
		exit(EXIT_FAILURE);
	}
}
