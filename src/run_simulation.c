/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_simulation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:02:55 by mdaan         #+#    #+#                 */
/*   Updated: 2022/10/26 17:37:05 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Create a thread for every Philosopher
	save in array of threads on heap
*/
int	create_threads(pthread_t **threads_ptr, t_philo **philos, int num_philos)
{
	int			i_philo;
	int			result_code;
	long long	start_time;

	*threads_ptr = malloc(sizeof(pthread_t) * num_philos);
	if (!*threads_ptr)
		return (error_msg("error creating thread\n", 0));
	start_time = current_time();
	(*philos)[0].specs->start_time = start_time;
	i_philo = 0;
	while (i_philo < num_philos)
	{
		(*philos)[i_philo].meal_time = start_time;
		result_code = pthread_create(&(*threads_ptr)[i_philo], NULL,
				routine, &(*philos)[i_philo]);
		if (result_code)
		{
			free(*threads_ptr);
			return (error_msg("error creating thread\n", 0));
		}
		i_philo++;
	}
	return (1);
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
	Create threads and start simulation
*/
int	run_simulation(t_args *specs, t_philo **philos)
{
	pthread_t	*threads;

	if (!create_threads(&threads, philos, specs->num_philos))
	{
		free(specs->forks);
		free(*philos);
		return (0);
	}
	wait_for_threads(&threads, specs->num_philos);
	destroy_forks(&(specs->forks), specs->num_philos);
	pthread_mutex_destroy(&(specs->death_mutex));
	free(specs->forks);
	free(*philos);
	free(threads);
	return (1);
}
