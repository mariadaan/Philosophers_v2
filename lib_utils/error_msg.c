/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_msg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:04:11 by mdaan         #+#    #+#                 */
/*   Updated: 2022/10/26 17:04:12 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_msg(char *msg, int error_code)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	return (error_code);
}
