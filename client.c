#include "minitalk.h"

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	pid;

		pid = ft_atoi(av[1]);
		if (pid < 1)
			exit(EXIT_FAILURE);
		kill(pid, SIGUSR1);


	}
	return 0;
}
