#include "philo.h"

int	error_msg(char *msg, int error_code)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	return (error_code);
}


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
void *routine(void *arg){
	t_philo *philo;

	// philosopher comes to life
	philo = arg;
	return NULL;
}

int		create_threads(pthread_t **threads_ptr, t_philo **philos, int num_philos)
{
	int			i_philo;
	int			result_code;
	pthread_t	*threads;

	threads = *threads_ptr;
	threads = malloc(sizeof(pthread_t) * num_philos);
	i_philo = 0;
	while (i_philo < num_philos)
	{
		// current_thread = threads[i_philo];
		printf("IN MAIN: Creating thread %d.\n", i_philo);
		result_code = pthread_create(&threads[i_philo], NULL, routine, &philos[i_philo]);
		if (result_code)
			return(error_msg("error creating thread\n", 0));
		i_philo++;
	}
	printf("IN MAIN: All threads are created.\n");
	return (1);
}

void	run_simulation(t_args *args, t_philo **philos)
{
	pthread_t	*threads;

	// create threads and start simulation
	if (!create_threads(&threads, philos, args->num_philos))
		return ;

}
