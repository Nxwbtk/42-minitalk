/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 02:27:51 by bsirikam          #+#    #+#             */
/*   Updated: 2023/03/05 03:02:50 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_decode(int sig)
{
	static int	count = 0;
	static char	c;

	if (sig == SIGUSR1)
	{
		c |= 1;
	}
	count++;
	if (count == 8)
	{
		write(1, &c, 1);
		count = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server : %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, ft_decode);
		signal(SIGUSR2, ft_decode);
	}
}
