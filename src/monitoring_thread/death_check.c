#include "philo.h"

/*
	let philo die and print die, only if it's the first one who died
*/
void	die(t_philo **philo)
{
	(*philo)->dead = true;
	pthread_mutex_lock(&((*philo)->specs->death_mutex));
	if ((*philo)->specs->anyone_dead)
	{
		pthread_mutex_unlock(&((*philo)->specs->death_mutex));
		return ;
	}	
	(*philo)->specs->anyone_dead = true;
	pthread_mutex_unlock(&((*philo)->specs->death_mutex));
	formatted_print(DIED, (*philo)->specs, (*philo)->i_philo + 1);
	return ;
}

/*
	return true if philo has died
	return false if philo has not died
*/
bool	am_i_dead(t_philo **philo)
{
	long long	time_since_meal;

	time_since_meal = current_time() - (*philo)->meal_time;
	if (time_since_meal > (*philo)->specs->time_to_die_micro)
	{
		die(philo);
		return (true);
	}
	return (false);
}

/*
	Check whether anyone has died
*/
bool	death_check(t_args *specs)
{
	pthread_mutex_lock(&(specs->death_mutex));
	if (specs->anyone_dead)
	{
		pthread_mutex_unlock(&(specs->death_mutex));
		return (true);
	}
	pthread_mutex_unlock(&(specs->death_mutex));
	return (false);
}
