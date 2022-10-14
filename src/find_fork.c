#include "philo.h"

// int	i_left_fork(int i_philo, int num_philos)
// {
// 	int	i_left_fork;

// 	if (i_philo == 0)
// 		i_left_fork = num_philos - 1;
// 	else
// 		i_left_fork = i_philo - 1;
// 	return (i_left_fork);
// }

int	i_left_fork(t_philo *philo)
{
	int	i_left_fork;

	if (philo->i_philo == 0)
		i_left_fork = philo->specs->num_philos - 1;
	else
		i_left_fork = philo->i_philo - 1;
	return (i_left_fork);
}

int	i_right_fork(t_philo *philo)
{
	return (philo->i_philo);
}