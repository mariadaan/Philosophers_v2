#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#include <stdio.h>

# define EXITCODE_SUCCESS 0
# define EXITCODE_FAIL 1

#define AVAILABLE 1
#define TAKEN 0

typedef struct s_args
{
	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
}		t_args;

typedef struct s_philo
{
	int		i_philo;
	int		eaten_meals;
	bool	l_fork;
	bool	r_fork;
	bool	eating;
	bool	sleeping;
	bool	dead;
	t_args	*specs;
}		t_philo;

/* src */
int		save_input(int argc, char **input, t_args *args);
t_philo	*init_philos(t_args *args);
void	run_simulation(t_args *args, t_philo **philos);


/* utils */
bool	is_pos_int(char *num_str);
bool	is_all_pos_ints(int rows, char **input);
char	*ft_itoa(int n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);

/* debug */
int		printnum(char *name, int num);
int		printfloat(char *name, float num);
int		printstr(char *name, char *str);
int		printchar(char *name, char c);
int		printco(char *name, int x, int y);
void	print2darray(char **array, int height);
void	print_philos(t_philo *philos, int num_philos);


#endif
