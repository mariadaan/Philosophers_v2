#include "philo.h"

/*
	Wait for all threads to finish
*/
void	wait_for_threads(pthread_t **threads_ptr, int num_philos)
{
	int	i_philo;

	i_philo = 0;
	while (i_philo < num_philos)
	{
		pthread_join((*threads_ptr)[i_philo], NULL);
		i_philo++;
	}
}

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

// /*
// 	stop all threads
// */
// void	end_simulation(t_args *specs)
// {
// 	printf("someone died. simulation stop here\n");
// }