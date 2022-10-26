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