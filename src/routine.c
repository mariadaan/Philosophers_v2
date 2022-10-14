#include "philo.h"

/*
	arg has the following information:
	int		i_philo;
	int		eaten_meals;
	bool	l_fork;
	bool	r_fork;
	bool	eating;
	bool	sleeping;
	bool	dead;

	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
*/
void *routine(void *arg)
{
	t_philo *philo;

	// philosopher comes to life
	philo = arg;
	printf("\nTHREAD %d: Started.\n", philo->i_philo);

	return NULL;
}