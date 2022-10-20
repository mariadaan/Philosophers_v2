#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#include <stdio.h>

# define EXITCODE_SUCCESS 0
# define EXITCODE_FAIL 1

# define THREAD_LIMIT 8000

enum e_type
{
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}		t_message;

typedef struct s_args
{
	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	long long		time_to_die_micro;
	long long		time_to_eat_micro;
	long long		time_to_sleep_micro;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_mutex;
	bool	anyone_dead;
}		t_args;

typedef struct s_philo
{
	int		i_philo;
	int		eaten_meals;
	bool	dead;
	long long		time_after_meal;
	t_args	*specs;
}		t_philo;

/* src */
int		save_input(int argc, char **input, t_args *args);
t_philo	*init_philos(t_args *args);
void	run_simulation(t_args *args, t_philo **philos);
void	*routine(void *arg);

/* utils */
int			i_left_fork(t_philo *philo);
int			i_right_fork(t_philo *philo);
long long	milli_to_micro(int milliseconds);
int			micro_to_milli(long long microseconds);
long long	current_time(void);
long long	time_since_start(long long start_time);
bool		am_i_dead(t_philo **philo);
void		protected_print(int message_enum, t_args *args, int philo_num);




// int		i_left_fork(int i_philo, int num_philos);

/* lib_utils */
bool	is_pos_int(char *num_str);
bool	is_all_pos_ints(int rows, char **input);
char	*ft_itoa(int n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		error_msg(char *msg, int error_code);




/* debug */
int		printnum(char *name, int num);
int		printlong(char *name, long long num);
int		printfloat(char *name, float num);
int		printstr(char *name, char *str);
int		printchar(char *name, char c);
int		printco(char *name, int x, int y);
void	print2darray(char **array, int height);
void	print_philos(t_philo *philos, int num_philos);
void	print_args(t_args args);




#endif
