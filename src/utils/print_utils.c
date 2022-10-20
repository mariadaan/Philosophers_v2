#include "philo.h"

/*
	timestamp_in_ms X has taken a fork
	timestamp_in_ms X is eating
	timestamp_in_ms X is sleeping
	timestamp_in_ms X is thinking
	timestamp_in_ms X died
*/
void	formatted_print(int message_enum, t_args *specs, int philo_num)
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

	timestamp_in_ms = time_since_start(specs->start_time);
	timestamp_in_ms = micro_to_milli(timestamp_in_ms);
	printf("%-8d %d %s\n", (int)timestamp_in_ms, philo_num, (char *)print_msg_lst[message_enum]);
}