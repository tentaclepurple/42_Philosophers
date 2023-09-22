/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:14:30 by imontero          #+#    #+#             */
/*   Updated: 2023/09/22 13:57:20 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

#define PHILMAX 250
#define ALIVE 0
#define	DEAD 1


typedef struct s_philos
{
	pthread_t		thread;
	int				philo_id;
	int				meals;
	int				dead_flag;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	
	int				c_philo_amount;
	size_t			c_start_time;
	size_t			c_time_2_die;
	size_t			c_time_2_eat;
	size_t			c_time_2_slp;
	int				c_max_meals;
	
	
	
}	t_philos;

void	fill_data(int ac, char **av, t_philos *ph, pthread_mutex_t *fork);
void	init_threads(t_philos *ph, pthread_mutex_t *fork);
void	*philo_routine(void *pointer);
void	*watcher_routine(void *pointer);
void	destroy_mutex(char *s, t_philos *ph, pthread_mutex_t *fork);
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_prints(t_philos *ph, char *s);
int		check_args(char **av);
void	ft_eat(t_philos *ph);
void	ft_sleep(t_philos *ph);
void	ft_think(t_philos *ph);


#endif