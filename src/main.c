/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:03:02 by mdaan         #+#    #+#                 */
/*   Updated: 2022/10/26 18:19:26 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	specs;
	t_philo	*philos;

	if (!save_input(argc, argv, &specs))
		return (EXIT_FAILURE);
	philos = init_philos(&specs);
	if (!philos)
		return (EXIT_FAILURE);
	print_args(specs);
	if (!run_simulation(&specs, &philos))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
