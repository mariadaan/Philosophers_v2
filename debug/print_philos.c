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
		printnum("dead", philo.dead);
		printf("----------------------------------\n");
		if (i != num_philos - 1)
			printf(" |\n |\n V\n");
		i++;
	}
}

void	print_args(t_args args)
{
	printf("----------------------------------\n");
	printnum("num_philos", args.num_philos);
	printnum("time_to_die", args.time_to_die);
	printnum("time_to_eat", args.time_to_eat);
	printnum("time_to_sleep", args.time_to_sleep);
	printf("----------------------------------\n");
}