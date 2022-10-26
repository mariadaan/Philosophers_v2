#include "philo.h"

/*
	Calculate how long a philo can sleep.
	If philo dies during sleep time, sleep until die time.
*/
void	philo_sleep(t_philo **philo)
{
	long long	sleep_time;
	long long	time_since_meal;

	time_since_meal = current_time() - (*philo)->meal_time;
	sleep_time = (*philo)->specs->time_to_die_micro - time_since_meal;
	if (sleep_time < (*philo)->specs->time_to_sleep_micro)
		usleep_better(sleep_time);
	else
		usleep_better((*philo)->specs->time_to_sleep_micro);
}

/*
	Calculate how long a philo can eat.
	If philo dies during eat time, eat until die time.
*/
void	philo_eat(t_philo **philo)
{
	long long	eat_time;
	long long	time_since_meal;

	time_since_meal = current_time() - (*philo)->meal_time;
	eat_time = (*philo)->specs->time_to_die_micro - time_since_meal;
	if (eat_time < (*philo)->specs->time_to_eat_micro)
		usleep_better(eat_time);
	else
		usleep_better((*philo)->specs->time_to_eat_micro);
}

/*
	let philo die and print die, only if it's the first one who died
*/
void	philo_die(t_philo **philo)
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

void	philo_starve(t_philo **philo)
{
	usleep_better((*philo)->specs->time_to_die_micro);
	pthread_mutex_unlock(&(*philo)->specs->forks[i_left_fork(*philo)]);
	philo_die(philo);
}