/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:14:30 by imontero          #+#    #+#             */
/*   Updated: 2023/09/29 18:57:12 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <signal.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

/* COLORS */
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE 	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define BOLD	"\033[0;1m"
# define X		"\033[0;0m"

/* MACROS */
# define PHILMAX 250
# define HASFORK 0
# define PRNTEAT 1
# define PRNTSLP 2
# define PRNTTHK 3
# define PRNTDIED 4
# define CONTINUE 0
# define END 1
# define EATING	1
# define NOTEATING 0

typedef struct s_philos
{
	pthread_t		thread;
	int				philo_id;
	int				meal_number;
	size_t			last_meal;	
	int				pid[PHILMAX];
	sem_t			*sem_meals;
	sem_t			*sem_lmeal;
	sem_t			*sem_prints;
	sem_t			*sem_forks;
	int				ending_flag;
	int				eating_flag;
	int				dead_flag;
	int				philo_amount;
	size_t			start_time;
	size_t			time_2_die;
	size_t			time_2_eat;
	size_t			time_2_slp;
	int				max_meals;

}					t_philos;


/* PROGRAM */
int		check_args(char **av);
void	init_philos(t_philos *ph);
void	*watcher_routine(void *pointer);
void	fill_data(int ac, char **av, t_philos *ph);
void	init_threads(t_philos *ph, pthread_mutex_t *fork);
void	exit_philo(t_philos *ph);

/* UTILS */
void	ft_error_exit(char *s);
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_prints(t_philos *ph, char *str);
void	*ft_memset(void *ptr, int c, size_t n);

#endif