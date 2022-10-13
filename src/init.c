#include "philo.h"

void	init_philos(t_args *args, t_philo **philos)
{
	int	i_philo;
	
	*philos = (t_philo *)malloc(sizeof(t_philo) * args->num_philos);
	i_philo = 0;
	while (i_philo < args->num_philos)
	{
		printnum("i", i_philo);
		(philos[i_philo])->i_philo = i_philo;
		(philos[i_philo])->eaten_meals = 0;
		(philos[i_philo])->l_fork = 0;
		(philos[i_philo])->r_fork = 0;
		(philos[i_philo])->eating = 0;
		(philos[i_philo])->sleeping = 0;
		(philos[i_philo])->dead = 0;
		(philos[i_philo])->specs = args;
		i_philo++;
	}
}