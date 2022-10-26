/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:03:02 by mdaan         #+#    #+#                 */
/*   Updated: 2022/10/26 17:03:02 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	specs;
	t_philo	*philos;

	if (!save_input(argc, argv, &specs))
		return (EXITCODE_FAIL);
	philos = init_philos(&specs);
	print_args(specs);
	printf("\nSTART SIMULATION\n");
	run_simulation(&specs, &philos);
	return (EXITCODE_SUCCESS);
}
