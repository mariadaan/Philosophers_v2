#include "philo.h"

bool	am_i_dead(t_philo **philo)
{
	long long	time_since_meal;

	time_since_meal = current_time() - (*philo)->meal_time;
	if (time_since_meal > (*philo)->specs->time_to_die_micro)
	{
		(*philo)->dead = true;
		pthread_mutex_lock(&((*philo)->specs->death_mutex));
		if ((*philo)->specs->anyone_dead)
		{
			pthread_mutex_unlock(&((*philo)->specs->death_mutex));
			return (true);
		}	
		(*philo)->specs->anyone_dead = true;
		pthread_mutex_unlock(&((*philo)->specs->death_mutex));
		formatted_print(DIED, (*philo)->specs, (*philo)->i_philo + 1);
		return (true);
	}
	return (false);
}

/* 
	TO DO:
	ZORGEN DAT IEMAND DOOD GAAT!! WAAROM GAAT NIEMAND DOOD

 */

bool	death_check(t_args *specs)
{
	pthread_mutex_lock(&(specs->death_mutex));
	if (specs->anyone_dead)
	{
		pthread_mutex_unlock(&(specs->death_mutex));
		return (true); //stop simulation
	}
	pthread_mutex_unlock(&(specs->death_mutex));
	return (false);
}


void *monitor_deaths(void *arg)
{
	t_args	*specs;

	specs = arg;
	// while (1)
	// {
	// 	if (death_check(specs))
	// 	{
	// 		end_simulation(specs);
	// 		break ;
	// 	}
	// }
	return (NULL);
}