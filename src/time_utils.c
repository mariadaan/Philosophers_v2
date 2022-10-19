#include <sys/time.h>

long long	milli_to_micro(int milliseconds)
{
	long long	microseconds;
	
	microseconds = milliseconds * 1000;
	return (microseconds);
}

int		micro_to_milli(long long microseconds)
{
	long long	milliseconds;
	
	milliseconds = microseconds / 1000;
	return (milliseconds);
}

/*
	current time since set time in history in microseconds
*/
long long	current_time(void)
{
	struct timeval	time_struct;
	long long		micro_seconds_time;

	gettimeofday(&time_struct, NULL);
	micro_seconds_time = time_struct.tv_sec * 1000000 + time_struct.tv_usec;
	return (micro_seconds_time);
}

/*
	time since start of simulation in microseconds
*/
int	time_since_start(int start_time)
{
	int	micro_seconds_time;
	int	time_since_start;

	micro_seconds_time = current_time();
	time_since_start = micro_seconds_time - start_time;
	return (time_since_start);
}