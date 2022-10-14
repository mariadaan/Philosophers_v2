/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:00:00 by mdaan         #+#    #+#                 */
/*   Updated: 2022/10/14 14:25:02 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (s)
	{
		len = ft_strlen((const char *)s);
		write(fd, s, len);
	}
}
