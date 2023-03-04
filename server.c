#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	ft_printf("Server : %d\n", pid);
	while (1)
		pause();
}
