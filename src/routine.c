/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:02:58 by mdaan         #+#    #+#                 */
/*   Updated: 2022/10/27 09:37:27 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	- pick up left fork
		return if anyone died
	- pick up right fork
		return if anyone died
	- print is eating
	- save start of meal in meal_time
	- eat (eating time long or until dead)
	- update number of meals
	- put forks back
*/
void	eat_philo(t_philo **philo)
{
	if (death_check((*philo)->specs))
		return ;
	if (!pick_up_fork(LEFT_FORK, philo))
		return ;
	if ((*philo)->specs->num_philos == 1)
		return (philo_starve(philo));
	if (!pick_up_fork(RIGHT_FORK, philo))
		return ;
	protected_print(EATING, philo);
	(*philo)->meal_time = current_time();
	philo_eat(philo);
	(*philo)->eaten_meals += 1;
	put_back_forks(philo);
}

/*
	Sleep time_to_sleep long, unless philo will die in sleep. 
	Then sleep until dead.
*/
void	sleep_philo(t_philo **philo)
{
	am_i_dead(philo);
	if (death_check((*philo)->specs))
		return ;
	protected_print(SLEEPING, philo);
	philo_sleep(philo);
}

/*
	the routine that every thread/philosopher keeps doing:
	think, eat, sleep, repeat
*/
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->i_philo % 2 == 0)
		usleep_better(50);
	while (!death_check(philo->specs))
	{
		am_i_dead(&philo);
		if (death_check(philo->specs))
			return (NULL);
		protected_print(THINKING, &philo);
		eat_philo(&philo);
		if (philo->specs->num_meals != -1
			&& philo->eaten_meals >= philo->specs->num_meals)
			return (NULL);
		sleep_philo(&philo);
	}
	return (NULL);
}
