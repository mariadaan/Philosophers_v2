#include "philo.h"

/*
	Check whether 2D array consists of integers only
	Returns
	- true if all ints
	- false if not all ints
*/
bool	is_all_ints(int rows, char **input)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (!(is_int(input[i])))
			return (false);
		i++;
	}
	return (true);
}
