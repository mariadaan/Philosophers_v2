#include "philo.h"

/*
	Check whether string contains an integer value
	Returns 1 if num is within integer value boundaries
	else, returns 0
*/
bool	is_int(char *num_str)
{
	int		num_int;
	char	*new_num_str;

	if (!num_str)
		return (0);
	num_int = ft_atoi(num_str);
	new_num_str = ft_itoa(num_int);
	if (ft_strcmp(num_str, new_num_str))
	{
		free(new_num_str);
		return (false);
	}
	free(new_num_str);
	return (true);
}