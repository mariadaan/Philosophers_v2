#include <sys/time.h>

long long	current_time(void)
{
	struct timeval	time_struct;
	long long		micro_seconds_time;

	gettimeofday(&time_struct, NULL);
	micro_seconds_time = time_struct.tv_sec * 1000000 + time_struct.tv_usec;
	return (micro_seconds_time);
}

int	time_since_start(int start_time)
{
	int	micro_seconds_time;
	int	time_since_start;

	micro_seconds_time = current_time();
	time_since_start = micro_seconds_time - start_time;
	return (time_since_start);
}