/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:14:30 by imontero          #+#    #+#             */
/*   Updated: 2023/09/27 11:50:07 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

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

typedef struct s_common
{
	pthread_mutex_t	prnt;
	pthread_mutex_t	eat;
	pthread_mutex_t	end;
}					t_common;

typedef struct s_philos
{
	pthread_t		thread;
	int				philo_id;
	int				meal_number;
	int				ending_flag;
	int				eating_flag;
	size_t			last_meal;	
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	int				c_philo_amount;
	size_t			c_start_time;
	size_t			c_time_2_die;
	size_t			c_time_2_eat;
	size_t			c_time_2_slp;
	int				c_max_meals;
	t_common		*common;
}					t_philos;

void	fill_data(int ac, char **av, t_philos *ph, pthread_mutex_t *fork);
void	init_threads(t_philos *ph, pthread_mutex_t *fork);
void	fill_mutex(t_philos *ph, t_common *com);
void	destroy_mutex(char *s, t_philos *ph, pthread_mutex_t *fork);
int		check_args(char **av);

/* ROUTINES */
void	*philo_routine(void *pointer);
void	ft_eat(t_philos *ph);
void	ft_sleep(t_philos *ph);
void	ft_think(t_philos *ph);
void	*watcher_routine(void *pointer);
int		check_end(t_philos *ph);
int		search_deads(t_philos *ph);
int		check_every1_ate(t_philos *ph);
void	ft_ending(t_philos *ph);

/* UTILS */
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_prints(t_philos *ph, int i);
void	ft_prints_aux(t_philos *ph, int i, size_t time);
void	*ft_memset(void *ptr, int c, size_t n);

#endif