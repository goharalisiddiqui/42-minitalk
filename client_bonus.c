/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:51:58 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/26 15:34:02 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	handler_func(int sig)
{
	return ;
}

void	sendchar(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(40);
		if (c & '\x01')
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		c = c >> 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					ind;
	int					size;
	struct sigaction	sa;

	if (argc != 3)
		return (1);
	sa.sa_handler = &handler_func;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	ind = -1;
	size = ft_strlen(argv[2]);
	while (++ind <= size)
		sendchar(argv[2][ind], atoi(argv[1]));
	return (0);
}
