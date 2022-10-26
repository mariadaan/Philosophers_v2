#include "philo.h"


// TO DO: deze functie opschonen
void	eat_philo(t_philo **philo)
{
	if (death_check((*philo)->specs))
		return ;
	// get forks
	pthread_mutex_lock(&(*philo)->specs->forks[i_left_fork(*philo)]); // left fork
	// checken of iemand dood is
	am_i_dead(philo);
	if (death_check((*philo)->specs))
	{
		pthread_mutex_unlock(&(*philo)->specs->forks[i_left_fork(*philo)]); // left fork
		return ;
	}
	// alleen printen dat ie vork gepakt heeft als er niemand dood is
	formatted_print(FORK, (*philo)->specs, (*philo)->i_philo + 1);

	if (i_right_fork(*philo) == -1)
	{
		usleep_better((*philo)->specs->time_to_die_micro);
		die(philo);
		return;
	}
	pthread_mutex_lock(&(*philo)->specs->forks[i_right_fork(*philo)]); // right fork
	// checken of iemand dood is
	am_i_dead(philo);
	if (death_check((*philo)->specs))
	{
		pthread_mutex_unlock(&(*philo)->specs->forks[i_right_fork(*philo)]); // right fork
		pthread_mutex_unlock(&(*philo)->specs->forks[i_left_fork(*philo)]); // left fork
		return ;
	}
	// alleen printen dat ie vork gepakt heeft als er niemand dood is
	formatted_print(FORK, (*philo)->specs, (*philo)->i_philo + 1);


	// eat for time_to_eat milliseconds
	formatted_print(EATING, (*philo)->specs, (*philo)->i_philo + 1);
	(*philo)->meal_time = current_time();
	philo_sleep(philo);

	// put forks back
	pthread_mutex_unlock(&(*philo)->specs->forks[i_left_fork(*philo)]); // left fork
	pthread_mutex_unlock(&(*philo)->specs->forks[i_right_fork(*philo)]); // right fork

	// formatted_print(DONE_EATING, (*philo)->specs, (*philo)->i_philo + 1);
}


// TO DO: usleep_better functie maken
void	sleep_philo(t_philo **philo)
{
	am_i_dead(philo);
	if (death_check((*philo)->specs))
		return ;
	formatted_print(SLEEPING, (*philo)->specs, (*philo)->i_philo + 1);
	philo_sleep(philo);
	// formatted_print(DONE_SLEEPING, (*philo)->specs, (*philo)->i_philo + 1);
}

/*
	the routine that every thread/philosopher keeps doing:
	think, eat, sleep, repeat
*/
void *routine(void *arg)
{
	t_philo *philo;

	// philosopher comes to life
	philo = arg;
	while (!death_check(philo->specs))
	{
		// think
		am_i_dead(&philo);
		if (death_check(philo->specs))
			return (NULL);
		formatted_print(THINKING, philo->specs, philo->i_philo + 1);

		// avoid death lock by making even numbers wait a tiny bit
		if (philo->i_philo % 2 == 0)
			usleep_better(200);

		// eat
		eat_philo(&philo);

		// TO DO: alleen gaan slapen als je ook echt gegeten hebt
		// sleep
		sleep_philo(&philo);
	}
	return (NULL);
}