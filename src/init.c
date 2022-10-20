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
		philos[i_philo].time_after_meal = 0;
		philos[i_philo].dead = false;
		philos[i_philo].specs = args;
		i_philo++;
	}
	return (philos);
}

int	fill_args(t_args *args, char **input)
{
	int	i_forks;

	i_forks = 0;
	args->num_philos = ft_atoi(input[1]);
	if (args->num_philos < 1 || args->num_philos > THREAD_LIMIT)
		return (0);
	args->time_to_die = ft_atoi(input[2]);
	args->time_to_eat = ft_atoi(input[3]);
	args->time_to_sleep = ft_atoi(input[4]);
	args->time_to_die_micro = milli_to_micro(args->time_to_die);
	args->time_to_eat_micro = milli_to_micro(args->time_to_eat);
	args->time_to_sleep_micro = milli_to_micro(args->time_to_sleep);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->num_philos);
	while (i_forks < args->num_philos)
	{
		pthread_mutex_init(&(args->forks[i_forks]), NULL);
		i_forks++;
	}
	pthread_mutex_init(&(args->death_mutex), NULL);
	args->anyone_dead = false;
	args->start_time = current_time();
	return (1);
}

/*
	Check whether input is integers only
	Returns
	- 0 if input is not valid
	- 1 if input is valid
*/
int	save_input(int argc, char **input, t_args *args)
{
	if (argc < 5
		|| !is_all_pos_ints(argc - 1, input + 1)
		|| !fill_args(args, input))
	{
		// TO DO: use write to fd 2
		printf("%s\n", "ERROR: invalid input\n\n"
		"expected usage:       ./philo <number_of_philosophers>"
		" <time_to_die> <time_to_eat> <time_to_sleep>\n"
		"optional extra arg:   <number_of_times_each_philosopher_must_eat>\n"
		"example input:        ./philo 3 200 100 150");
		return (0);
	}
	return (1);
}
