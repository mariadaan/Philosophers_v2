#include <sys/time.h>

int	current_time(void)
{
	struct timeval	current_time;
	int				micro_seconds_time;

	gettimeofday(&current_time, NULL);
	micro_seconds_time = (current_time.tv_sec * 1000000) + current_time.tv_usec;
	return (micro_seconds_time);
}