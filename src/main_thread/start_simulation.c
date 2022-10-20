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
void	wait_for_threads(pthread_t **threads_ptr, pthread_t *mon_thread, int num_philos)
{
	int	i_philo;

	i_philo = 0;
	while (i_philo < num_philos)
	{
		pthread_join((*threads_ptr)[i_philo], NULL);
		pthread_join(*mon_thread, NULL);
		i_philo++;
	}
}

int		create_mon_thread(pthread_t *mon_thread, t_args *specs)
{
	int	result_code;

	*mon_thread = malloc(sizeof(pthread_t));
	result_code = pthread_create(mon_thread, NULL, monitor_deaths, specs);
	if (result_code)
		return(error_msg("error creating monitoring thread\n", 0));
	return (1);
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
		result_code = pthread_create(&(*threads_ptr)[i_philo], NULL, routine, &(*philos)[i_philo]);
		if (result_code)
			return(error_msg("error creating thread\n", 0));
		i_philo++;
	}
	return (1);
}

void	run_simulation(t_args *specs, t_philo **philos)
{
	pthread_t	*threads;
	pthread_t	mon_thread;

	// create threads and start simulation
	if (!create_mon_thread(&mon_thread, specs)
		|| !create_threads(&threads, philos, specs->num_philos))
		return ;
	wait_for_threads(&threads, &mon_thread, specs->num_philos);
	destroy_forks(&(specs->forks), specs->num_philos);
}
