#include "philo.h"

bool	am_i_dead(t_philo **philo)
{
	long long	time_since_meal;
	int			time_to_die_micro;

	time_to_die_micro = milli_to_micro((*philo)->specs->time_to_die);
	time_since_meal = (*philo)->time_after_meal - (*philo)->specs->start_time;
	if (time_since_meal > time_to_die_micro)
	{
		printf("HALLO?\n\n");
		// WAAROM KOMT NIEMAND HIER!? TESTEN!!
		pthread_mutex_lock(&((*philo)->specs->death_mutex));
		(*philo)->specs->anyone_dead = true;
		pthread_mutex_unlock(&((*philo)->specs->death_mutex));
		protected_print(DIED, (*philo)->specs, (*philo)->i_philo + 1);
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

/*
	timestamp_in_ms X has taken a fork
	timestamp_in_ms X is eating
	timestamp_in_ms X is sleeping
	timestamp_in_ms X is thinking
	timestamp_in_ms X died
*/
void	protected_print(int message_enum, t_args *args, int philo_num)
{
	long long	timestamp_in_ms;
	const char	*print_msg_lst[]
		= {
		" has taken a fork",
		" is eating",
		" is sleeping",
		" is thinking",
		" died"
	};

	timestamp_in_ms = time_since_start(args->start_time);
	timestamp_in_ms = micro_to_milli(timestamp_in_ms);
	printf("%-8d %d %s\n", (int)timestamp_in_ms, philo_num, (char *)print_msg_lst[message_enum]);
}