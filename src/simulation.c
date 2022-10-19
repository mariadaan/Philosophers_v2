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
	Create a thread for every Philosopher
	save in array of threads on heap
*/
int		create_threads(pthread_t **threads_ptr, t_philo **philos, int num_philos)
{
	int	i_philo;
	int	result_code;

	*threads_ptr = malloc(sizeof(pthread_t) * num_philos);
	i_philo = 0;
	while (i_philo < num_philos)
	{
		// printf("IN MAIN: Creating thread %d.\n", i_philo);
		result_code = pthread_create(&(*threads_ptr)[i_philo], NULL, routine, &(*philos)[i_philo]);
		if (result_code)
			return(error_msg("error creating thread\n", 0));
		i_philo++;
	}
	// printf("IN MAIN: All threads are created.\n");
	return (1);
}

void	run_simulation(t_args *args, t_philo **philos)
{
	pthread_t	*threads;

	// create threads and start simulation
	if (!create_threads(&threads, philos, args->num_philos))
		return ;
	wait_for_threads(&threads, args->num_philos);

}
