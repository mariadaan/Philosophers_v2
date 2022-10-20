#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philos;

	if (!save_input(argc, argv, &args))
		return (EXITCODE_FAIL);
	philos = init_philos(&args);
	print_args(args);
	printf("\nSTART SIMULATION\n");
	run_simulation(&args, &philos);
	return (EXITCODE_SUCCESS);
}