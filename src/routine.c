#include "philo.h"

void	eat_philo(t_philo **philo)
{
	// eat
	pthread_mutex_lock(&(*philo)->specs->forks[i_left_fork(*philo)]); // left fork
	pthread_mutex_lock(&(*philo)->specs->forks[i_right_fork(*philo)]); // right fork
	printf("\nTHREAD %d: Start eating\n", (*philo)->i_philo);
	printf("THREAD %d: Will be eating for %d milliseconds.\n", (*philo)->i_philo, (*philo)->specs->time_to_eat);	
	usleep(milli_to_micro((*philo)->specs->time_to_eat));
	pthread_mutex_unlock(&(*philo)->specs->forks[i_left_fork(*philo)]); // left fork
	pthread_mutex_unlock(&(*philo)->specs->forks[i_right_fork(*philo)]); // right fork
	printf("THREAD %d: Done eating.\n", (*philo)->i_philo);
}

void	sleep_philo(t_philo **philo)
{
	printf("THREAD %d: Will be sleeping for %d milliseconds.\n", (*philo)->i_philo, (*philo)->specs->time_to_sleep);
	usleep(milli_to_micro((*philo)->specs->time_to_sleep));
}

/*
	the routine that every thread/philosopher keeps doing:
	think, eat, sleep, repeat
*/
void *routine(void *arg)
{
	t_philo *philo;
	int	num_philos;

	// philosopher comes to life
	philo = arg;
	num_philos = philo->specs->num_philos;
	printf("\nTHREAD %d: Started.\n", philo->i_philo);
	while (!philo->dead)
	{
		// think
		printf("\nTHREAD %d: Start thinking\n", philo->i_philo);
		if (philo->i_philo % 2 == 0)
			usleep(100);

		// eat
		eat_philo(&philo);

		// sleep
		sleep_philo(&philo);
		philo->dead = true;
		printf("\nTHREAD %d: Died\n", philo->i_philo);
	}

	printf("THREAD %d: Ended.\n\n", philo->i_philo);

	return (NULL);
}