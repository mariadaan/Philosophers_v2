#include "philo.h"

void	eat_philo(t_philo **philo)
{
	// get forks
	pthread_mutex_lock(&(*philo)->specs->forks[i_left_fork(*philo)]); // left fork
	// checken of iemand dood is
	protected_print(FORK, (*philo)->specs, (*philo)->i_philo + 1);
	pthread_mutex_lock(&(*philo)->specs->forks[i_right_fork(*philo)]); // right fork
	// checken of iemand dood is
	protected_print(FORK, (*philo)->specs, (*philo)->i_philo + 1);

	// eat for time_to_eat milliseconds
	protected_print(EATING, (*philo)->specs, (*philo)->i_philo + 1);
	usleep(milli_to_micro((*philo)->specs->time_to_eat));

	// put forks back
	pthread_mutex_unlock(&(*philo)->specs->forks[i_left_fork(*philo)]); // left fork
	pthread_mutex_unlock(&(*philo)->specs->forks[i_right_fork(*philo)]); // right fork

	// save time after last meal in philo data
	(*philo)->time_after_meal = current_time();
}

void	sleep_philo(t_philo **philo)
{
	protected_print(SLEEPING, (*philo)->specs, (*philo)->i_philo + 1);
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
	while (!philo->dead)
	{
		// think
		protected_print(THINKING, philo->specs, philo->i_philo + 1);
		if (philo->i_philo % 2 == 0)
			usleep(100);

		// eat
		eat_philo(&philo);

		// sleep
		sleep_philo(&philo);
		philo->dead = am_i_dead(&philo);
	}

	return (NULL);
}