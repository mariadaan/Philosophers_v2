#include "philo.h"

bool	am_i_dead(t_philo **philo)
{
	long long	time_since_meal;
	long long	time_to_die_micro;

	time_to_die_micro = milli_to_micro((*philo)->specs->time_to_die);
	time_since_meal = (*philo)->time_after_meal - (*philo)->specs->start_time;
	// printlong("time_since_meal", time_since_meal);
	// printlong("time_to_die_micro", time_to_die_micro);
	if (time_since_meal > time_to_die_micro)
	{
		formatted_print(DIED, (*philo)->specs, (*philo)->i_philo + 1);
		pthread_mutex_lock(&((*philo)->specs->death_mutex));
		(*philo)->specs->anyone_dead = true;
		pthread_mutex_unlock(&((*philo)->specs->death_mutex));
		return (true);
	}
	return (false);
}

/* 
	TO DO:
	ZORGEN DAT IEMAND DOOD GAAT!! WAAROM GAAT NIEMAND DOOD

 */

bool	death_check(t_args *args)
{
	pthread_mutex_lock(&(args->death_mutex));
	if (args->anyone_dead)
	{
		printf("\n\nsomeone died\n\n");
		return (true); //stop simulation
	}
	pthread_mutex_unlock(&(args->death_mutex));
	return (false);
}
