#include "philo.h"

int	error_msg(char *msg, int error_code)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	return (error_code);
}
