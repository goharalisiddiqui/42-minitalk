/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:44:20 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/19 17:01:26 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handler_func(int sig)
{
	static char c;
	static char	n = '\x01';

	if (sig == SIGUSR2)
		c = c ^ n;
	if (n < 0)
	{
		if (c == '\0')
			c = '\n';
		write(1, &c, 1);
		n = '\x01';
		c = 0;
	}
	else
		n = n << 1;
}

int	main(void)
{
	struct sigaction sa;

	sa.sa_handler = &handler_func;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	while (1)
		pause();
	return (0);
}