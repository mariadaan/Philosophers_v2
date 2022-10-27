/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:02:51 by mdaan         #+#    #+#                 */
/*   Updated: 2022/10/27 09:37:33 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

long long	milli_to_micro(int milliseconds)
{
	long long	microseconds;

	microseconds = (long long)milliseconds * 1000;
	return (microseconds);
}

int	micro_to_milli(long long microseconds)
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
long long	time_since_start(long long start_time)
{
	long long	micro_seconds_time;
	long long	time_since_start;

	micro_seconds_time = current_time();
	time_since_start = micro_seconds_time - start_time;
	return (time_since_start);
}

/*
	Usleep has a delay. This function optimizes usleep.
*/
void	usleep_better(long long microseconds)
{
	long long	start_time;

	start_time = current_time();
	while (current_time() - start_time < microseconds)
		usleep(100);
}
