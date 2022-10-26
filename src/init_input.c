#include "philo.h"

/*
	Save all Philosophers in array
	initialize all values
	save user input values in specs
*/
t_philo	*init_philos(t_args *specs)
{
	t_philo	*philos;
	int		i_philo;

	philos = (t_philo *)malloc(sizeof(t_philo) * specs->num_philos);
	i_philo = 0;
	while (i_philo < specs->num_philos)
	{
		philos[i_philo].i_philo = i_philo;
		philos[i_philo].eaten_meals = 0;
		philos[i_philo].meal_time = specs->start_time;
		philos[i_philo].dead = false;
		philos[i_philo].specs = specs;
		i_philo++;
	}
	return (philos);
}

void	init_forks(t_args *specs)
{
	int	i_forks;

	i_forks = 0;
	while (i_forks < specs->num_philos)
	{
		pthread_mutex_init(&(specs->forks[i_forks]), NULL);
		i_forks++;
	}
}

int	fill_specs(t_args *specs, char **input)
{
	specs->num_philos = ft_atoi(input[1]);
	if (specs->num_philos < 1 || specs->num_philos > THREAD_LIMIT)
		return (0);
	specs->time_to_die = ft_atoi(input[2]);
	specs->time_to_eat = ft_atoi(input[3]);
	specs->time_to_sleep = ft_atoi(input[4]);
	specs->time_to_die_micro = milli_to_micro(specs->time_to_die);
	specs->time_to_eat_micro = milli_to_micro(specs->time_to_eat);
	specs->time_to_sleep_micro = milli_to_micro(specs->time_to_sleep);
	specs->forks = malloc(sizeof(pthread_mutex_t) * specs->num_philos);
	init_forks(specs);
	pthread_mutex_init(&(specs->death_mutex), NULL);
	specs->anyone_dead = false;
	specs->start_time = current_time();
	return (1);
}

/*
	Check whether input is integers only
	Returns
	- 0 if input is not valid
	- 1 if input is valid

	if valid, save all input in specs
*/
int	save_input(int argc, char **input, t_args *specs)
{
	if (argc < 5
		|| !is_all_pos_ints(argc - 1, input + 1)
		|| !fill_specs(specs, input))
	{
		printf("%s\n", "ERROR: invalid input\n\n"
			"expected usage:       ./philo <number_of_philosophers>"
			" <time_to_die> <time_to_eat> <time_to_sleep>\n"
			"optional extra arg:   <number_of_times_each_philosopher_must_eat>\n"
			"example input:        ./philo 3 200 100 150");
		return (0);
	}
	return (1);
}
