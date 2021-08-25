/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:45:16 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/16 14:39:40 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_initvars(char *r, char **s, char **t, int *size)
{
	*r = 'a';
	*s = NULL;
	*t = NULL;
	*size = 0;
}

static void	ft_copytostr(char *str, char *temp, int size, int lastchar)
{
	int	i;

	i = 0;
	while (i < size)
	{
		*(temp + i) = *(str + i);
		i++;
	}
	*(temp + i) = lastchar;
}

int	get_next_line(int fd, char **line)
{
	char	*str;
	char	*temp;
	char	readchar;
	int		flag;
	int		size;

	ft_initvars(&readchar, &str, &temp, &size);
	while (readchar)
	{
		flag = read(fd, &readchar, 1);
		if (flag == -1)
		{
			if (str != NULL)
				free(str);
			return (-1);
		}
		if (readchar == '\n' || flag == 0)
			readchar = '\0';
		temp = malloc((size + 1) * sizeof(char));
		ft_copytostr(str, temp, size++, readchar);
		free(str);
		str = temp;
	}
	*line = str;
	return (flag);
}
