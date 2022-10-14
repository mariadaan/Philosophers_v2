#include "philo.h"

void	print_philos(t_philo *philos, int num_philos)
{
	int		i;
	t_philo	philo;

	i = 0;
	while (i < num_philos)
	{
		philo = philos[i];
		printf("----------------------------------\n");
		printf("Philosopher #%d:\n", i + 1);
		printnum("i_philo", philo.i_philo);
		printnum("eaten_meals", philo.eaten_meals);
		printnum("l_fork", philo.l_fork);
		printnum("r_fork", philo.r_fork);
		printnum("eating", philo.eating);
		printnum("sleeping", philo.sleeping);
		printnum("dead", philo.dead);
		printf("----------------------------------\n");
		if (i != num_philos - 1)
			printf(" |\n |\n V\n");
		i++;
	}
}