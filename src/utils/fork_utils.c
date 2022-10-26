#include "philo.h"

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
	if (philo->specs->num_philos == 1)
		return (-1);
	return (philo->i_philo);
}

/*
	return false when someone died while waiting for fork mutex
	return true when successfully picked up fork
*/
bool	pick_up_fork(int fork_type, t_philo **philo)
{
	int	i_fork;

	if (fork_type == LEFT_FORK)
		i_fork = i_left_fork(*philo);
	else
		i_fork = i_right_fork(*philo);
	pthread_mutex_lock(&(*philo)->specs->forks[i_fork]);
	am_i_dead(philo);
	if (death_check((*philo)->specs))
	{
		if (fork_type == RIGHT_FORK)
			pthread_mutex_unlock(&(*philo)->specs->forks[i_fork]);
		pthread_mutex_unlock(&(*philo)->specs->forks[i_left_fork(*philo)]);
		return (false);
	}
	protected_print(FORK, philo);
	return (true);
}

/*
	Unlock left and right fork mutex
*/
void	put_back_forks(t_philo **philo)
{
	pthread_mutex_unlock(&(*philo)->specs->forks[i_left_fork(*philo)]);
	pthread_mutex_unlock(&(*philo)->specs->forks[i_right_fork(*philo)]);
}

/*
	Destroy forks
*/
void	destroy_forks(pthread_mutex_t **forks, int num_philos)
{
	int	i_fork;

	i_fork = 0;
	while (i_fork < num_philos)
	{
		pthread_mutex_destroy(&(*forks)[i_fork]);
		i_fork++;
	}
}
