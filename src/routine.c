#include "philo.h"

bool	am_i_dead(t_philo **philo)
{
	long long	time_since_meal;
	int			time_to_die_micro;

	time_to_die_micro = milli_to_micro((*philo)->specs->time_to_die);
	time_since_meal = (*philo)->time_after_meal - (*philo)->specs->start_time;
	if (time_since_meal > time_to_die_micro)
		return (true);
	return (false);
}

void	eat_philo(t_philo **philo)
{
	// eat
	pthread_mutex_lock(&(*philo)->specs->forks[i_left_fork(*philo)]); // left fork
	pthread_mutex_lock(&(*philo)->specs->forks[i_right_fork(*philo)]); // right fork
	printf("philo %d: Start eating\n", (*philo)->i_philo);
	printf("philo %d: Will be eating for %d milliseconds.\n", (*philo)->i_philo, (*philo)->specs->time_to_eat);	
	usleep(milli_to_micro((*philo)->specs->time_to_eat));
	pthread_mutex_unlock(&(*philo)->specs->forks[i_left_fork(*philo)]); // left fork
	pthread_mutex_unlock(&(*philo)->specs->forks[i_right_fork(*philo)]); // right fork
	(*philo)->time_after_meal = current_time();
	printf("philo %d: Done eating.\n", (*philo)->i_philo);
}

void	sleep_philo(t_philo **philo)
{
	printf("philo %d: Will be sleeping for %d milliseconds.\n", (*philo)->i_philo, (*philo)->specs->time_to_sleep);
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
	// printf("\nphilo %d: Started.\n", philo->i_philo);
	while (!philo->dead)
	{
		// think
		printf("philo %d: Will be thinking for ??? seconds\n", philo->i_philo);
		if (philo->i_philo % 2 == 0)
			usleep(100);

		// eat
		eat_philo(&philo);

		// sleep
		sleep_philo(&philo);
		philo->dead = am_i_dead(&philo);
		printf("philo %d: Died\n", philo->i_philo);
	}

	printf("philo %d: Ended.\n", philo->i_philo);

	return (NULL);
}