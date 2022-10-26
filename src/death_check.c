/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   death_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:00:26 by mdaan         #+#    #+#                 */
/*   Updated: 2022/10/26 17:00:30 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	return true if philo has died
		- set anyone_dead to true
		- set philo->dead to true
	return false if philo has not died
*/
bool	am_i_dead(t_philo **philo)
{
	long long	time_since_meal;

	time_since_meal = current_time() - (*philo)->meal_time;
	if (time_since_meal > (*philo)->specs->time_to_die_micro)
	{
		philo_die(philo);
		return (true);
	}
	return (false);
}

/*
	Check whether anyone has died
*/
bool	death_check(t_args *specs)
{
	pthread_mutex_lock(&(specs->death_mutex));
	if (specs->anyone_dead)
	{
		pthread_mutex_unlock(&(specs->death_mutex));
		return (true);
	}
	pthread_mutex_unlock(&(specs->death_mutex));
	return (false);
}
