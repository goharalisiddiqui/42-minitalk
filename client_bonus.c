/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:51:58 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/19 19:55:43 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	handler_func(int sig)
{
	
}

int	main(int argc, char **argv)
{
	int		ind;
	int		i;
	char	c;
	int 	size;
	struct	sigaction sa;

	time_t begin = time(NULL);
	if (argc != 3)
		return (1);
	sa.sa_handler = &handler_func;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	ind = -1;
	size = ft_strlen(argv[2]);
	while (++ind <= size)
	{
		i = 0;
		c = argv[2][ind];
		while (i < 8)
		{
			usleep(25);
			if (c & '\x01')
				kill(atoi(argv[1]), SIGUSR2);
			else
				kill(atoi(argv[1]), SIGUSR1);
			pause();
			c = c >> 1;
			i++;
		}
	}
	time_t end = time(NULL);
	printf("The elapsed time is %ld seconds bytes per sec = %ld", (end - begin), size/(end - begin));
	return (0);
}

