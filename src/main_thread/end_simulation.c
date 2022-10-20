#include "philo.h"

/*
	Destroy forks
*/
void	destroy_forks(pthread_mutex_t **forks, int num_philos)
{
	int	i_fork;

	i_fork = 0;
	while (i_fork < num_philos)
	{
		pthread_mutex_destroy(&(*forks)[i_fork]);
		i_fork++;
	}
}

/*
	stop all threads
*/
void	end_simulation(t_args *specs)
{
	printf("someone died. simulation stop here\n");
}