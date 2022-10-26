#include "philo.h"

/*
	Create a monitoring thread that keeps checking whether anyone died
*/
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
	long long start_time;

	*threads_ptr = malloc(sizeof(pthread_t) * num_philos);
	start_time = current_time();
	(*philos)[0].specs->start_time = start_time;
	i_philo = 0;
	while (i_philo < num_philos)
	{
		(*philos)[i_philo].meal_time = start_time;
		result_code = pthread_create(&(*threads_ptr)[i_philo], NULL, routine, &(*philos)[i_philo]);
		if (result_code)
			return(error_msg("error creating thread\n", 0));
		i_philo++;
	}
	return (1);
}

/*
	Create threads and start simulation
*/
void	run_simulation(t_args *specs, t_philo **philos)
{
	pthread_t	*threads;
	pthread_t	mon_thread;

	if (!create_mon_thread(&mon_thread, specs)
		|| !create_threads(&threads, philos, specs->num_philos))
		return ;
	wait_for_threads(&threads, &mon_thread, specs->num_philos);
	destroy_forks(&(specs->forks), specs->num_philos);
	pthread_mutex_destroy(&(specs->death_mutex));
}
