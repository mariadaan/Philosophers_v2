#include "philo.h"

int	fill_args(t_args *args, char **input)
{
	int	i_forks;

	i_forks = 0;
	args->num_philos = ft_atoi(input[1]);
	if (args->num_philos < 1)
		return (0);
	args->time_to_die = ft_atoi(input[2]);
	args->time_to_eat = ft_atoi(input[3]);
	args->time_to_sleep = ft_atoi(input[4]);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->num_philos);
	while (i_forks < args->num_philos)
	{
		pthread_mutex_init(&(args->forks[i_forks]), NULL);
		i_forks++;
	}
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
