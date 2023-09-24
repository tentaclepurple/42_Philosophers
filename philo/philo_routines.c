/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:32:12 by imontero          #+#    #+#             */
/*   Updated: 2023/09/24 20:52:50 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philos *ph)
{
	printf("%zu id: %i, endflg: %i\n", get_current_time() -  ph->c_start_time, ph->philo_id, ph->ending_flag);
/*	if (ph->ending_flag == END)
		return ;*/
	pthread_mutex_lock(ph->fork_l);
/*	if (ph->ending_flag == END)
		return ;*/
	ft_prints(ph, HASFORK);
	pthread_mutex_lock(ph->fork_r);
/*	if (ph->ending_flag == END)
		return ;*/
	ft_prints(ph, HASFORK);
/*	if (ph->ending_flag == END)
		return ;*/
	ft_prints(ph, PRNTEAT);
/*	if (ph->ending_flag == END)
		return ;*/
	ph->eating_flag = EATING;
	ph->meal_number++;
	ph->last_meal = get_current_time();
/*	if (ph->ending_flag == END)
		return ;*/
	ft_usleep(ph->c_time_2_eat);
	ph->eating_flag = NOTEATING;
	pthread_mutex_unlock(ph->fork_l);
	pthread_mutex_unlock(ph->fork_r);
}

void	ft_sleep(t_philos *ph)
{
	ft_prints(ph, PRNTSLP);
	ft_usleep(ph->c_time_2_slp);
}

void	ft_think(t_philos *ph)
{
	ft_prints(ph, PRNTTHK);
}

/*void	ft_eat(t_philos *ph)
{
	pthread_mutex_lock(ph->fork_l);
	ft_prints(ph, "has taken a fork");
	pthread_mutex_lock(ph->fork_r);
	ft_prints(ph, "has taken a fork");
	ft_prints(ph, "is eating");
	ft_usleep(ph->c_time_2_eat);
	pthread_mutex_unlock(ph->fork_l);
	pthread_mutex_unlock(ph->fork_r);
}

void	ft_sleep(t_philos *ph)
{
	ft_prints(ph, "is sleeping");
	ft_usleep(ph->c_time_2_slp);
}

void	ft_think(t_philos *ph)
{
	ft_prints(ph, "is thinking");
}
*/


/*void	*philo_routine(void *pointer)
{
	t_philos	*ph;
	int i = 0;
	ph = (t_philos *)pointer;
	i++;
	printf("er filo ph %i\n", i);
	return (pointer);
}*/

/*void	*watcher_routine(void *pointer)
{
	t_philos	*ph;
	//int i;
	
	ph = (t_philos *)pointer;
	//i = 0;
	i = ph->philo_id;
	while (i < ph->c_philo_amount)
		printf("el watchel %i\n", (ph[i++].philo_id));
	return (pointer);
}*/