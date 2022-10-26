#include "philo.h"


// TO DO: deze functie opschonen
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
void *routine(void *arg)
{
	t_philo *philo;

	philo = arg;
	while (!death_check(philo->specs))
	{
		// think
		am_i_dead(&philo);
		if (death_check(philo->specs))
			return (NULL);
		protected_print(THINKING, &philo);
		// avoid death lock by making even numbers wait a tiny bit
		if (philo->i_philo % 2 == 0)
			usleep_better(200);
		eat_philo(&philo);
		sleep_philo(&philo);
	}
	return (NULL);
}