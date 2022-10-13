#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philos;

	if (!save_input(argc, argv, &args))
		return (EXITCODE_FAIL);
	init_philos(&args, &philos);
	run_simulation(&args, &philos);
	return (EXITCODE_SUCCESS);
}