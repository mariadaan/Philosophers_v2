/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_all_pos_ints.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:00:23 by mdaan         #+#    #+#                 */
/*   Updated: 2022/10/26 17:00:23 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Check whether 2D array consists of integers only
	Returns
	- true if all ints
	- false if not all ints
*/
bool	is_all_pos_ints(int rows, char **input)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (!(is_pos_int(input[i])))
			return (false);
		i++;
	}
	return (true);
}
