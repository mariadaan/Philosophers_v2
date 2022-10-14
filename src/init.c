#include "philo.h"


/*
	Save all Philosophers in array
	initialize all values
	save user input values in specs
*/
t_philo	*init_philos(t_args *args)
{
	t_philo	*philos;
	int		i_philo;
	
	philos = (t_philo *)malloc(sizeof(t_philo) * args->num_philos);
	i_philo = 0;
	while (i_philo < args->num_philos)
	{
		philos[i_philo].i_philo = i_philo;
		philos[i_philo].eaten_meals = 0;
		philos[i_philo].l_fork = false;
		philos[i_philo].r_fork = false;
		philos[i_philo].eating = false;
		philos[i_philo].sleeping = false;
		philos[i_philo].dead = false;
		philos[i_philo].specs = args;
		i_philo++;
	}
	return (philos);
}