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


/*
	timestamp_in_ms X has taken a fork
	timestamp_in_ms X is eating
	timestamp_in_ms X is sleeping
	timestamp_in_ms X is thinking
	timestamp_in_ms X died
*/
void	protected_print(int message_enum, t_args *args, int philo_num)
{
	int	timestamp_in_ms;
	const char	*print_msg_lst[]
		= {
		" has taken a fork",
		" is eating",
		" is sleeping",
		" is thinking",
		" died"
	};

	timestamp_in_ms = time_since_start(args->start_time);
	printf("%-8d %d %s\n", timestamp_in_ms, philo_num, (char *)print_msg_lst[message_enum]);
}