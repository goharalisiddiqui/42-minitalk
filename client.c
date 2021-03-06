/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:51:58 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/26 14:55:52 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	int		ind;
	int		i;
	char	c;
	int		size;

	if (argc != 3)
		return (1);
	ind = -1;
	size = ft_strlen(argv[2]);
	while (++ind <= size)
	{
		i = 0;
		c = argv[2][ind];
		while (i < 7)
		{
			if (c & '\x01')
				kill(atoi(argv[1]), SIGUSR2);
			else
				kill(atoi(argv[1]), SIGUSR1);
			c = c >> 1;
			i++;
			usleep(40);
		}
	}
	return (0);
}
