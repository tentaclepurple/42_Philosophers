/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:14:30 by imontero          #+#    #+#             */
/*   Updated: 2023/09/21 16:17:29 by imontero         ###   ########.fr       */
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
	pthread_mutex_t	fork_r;
	pthread_mutex_t	fork_l;
	
	int				c_philo_amount;
	size_t			c_start_time;
	size_t			c_time_2_die;
	size_t			c_time_2_eat;
	size_t			c_time_2_slp;
	int				c_max_meals;
	
	
	
}	t_philos;

void	fill_common_data(int ac, char **av, t_philos **ph);
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		check_args(char **av);


#endif