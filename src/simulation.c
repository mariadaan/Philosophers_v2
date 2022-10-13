#include "philo.h"

void	run_simulation(t_args *args, t_philo **philos)
{
	exit(0);
	// start simulation
	// while (philo_index < args->num_philos && philo_index > 0)
	// {
	// 	printf("IN MAIN: Creating thread %d.\n", philo_index);
	// 	result_code = pthread_create(&threads[philo_index], NULL, routine, &(philos[philo_index]));
	// 	if (result_code)
	// 		return(error_msg("error creating thread\n", 1));
	// 	philo_index++;
	// }

	// printf("IN MAIN: All threads are created.\n");

	// // wait for all threads to finish
	// philo_index = 0;
	// while (philo_index < args->num_philos)
	// {
	// 	pthread_join(threads[philo_index], NULL);
	// 	philo_index++;
	// }

	// destroy_forks(args->forks, args->num_philos);
	// return (0);
}
