/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_pos_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:03:15 by mdaan         #+#    #+#                 */
/*   Updated: 2022/10/26 17:03:17 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Check whether string contains a positive integer value
	Returns 1 if num is within integer value boundaries
	else, returns 0
*/
bool	is_pos_int(char *num_str)
{
	int		num_int;
	char	*new_num_str;

	if (!num_str)
		return (false);
	num_int = ft_atoi(num_str);
	if (num_int < 0)
		return (false);
	new_num_str = ft_itoa(num_int);
	if (ft_strcmp(num_str, new_num_str))
	{
		free(new_num_str);
		return (false);
	}
	free(new_num_str);
	return (true);
}
