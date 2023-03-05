/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 02:27:54 by bsirikam          #+#    #+#             */
/*   Updated: 2023/03/05 02:41:42 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	one(int pid)
{
	if (kill(pid, SIGUSR1) == -1)
		exit(EXIT_SUCCESS);
}

void	two(int pid)
{
	if (kill(pid, SIGUSR2) == -1)
		exit(EXIT_SUCCESS);
}

void	ft_encode(int pid, char *str)
{
	int		i;
	char	c;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 7;
		c = str[i++];
		while (j >= 0)
		{
			if ((c >> j) & 1)
				one(pid);
			else
				two(pid);
			j--;
			usleep(120);
		}
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 1)
			exit(EXIT_FAILURE);
		ft_encode(pid, av[2]);
	}
	return (0);
}
