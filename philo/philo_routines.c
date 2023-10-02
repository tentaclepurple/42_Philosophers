/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:32:12 by imontero          #+#    #+#             */
/*   Updated: 2023/09/26 17:42:04 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philos *ph)
{
	pthread_mutex_lock(ph->fork_l);
	ft_prints(ph, HASFORK);
	pthread_mutex_lock(ph->fork_r);
	ft_prints(ph, HASFORK);
	ft_prints(ph, PRNTEAT);
	ph->eating_flag = EATING;
	pthread_mutex_lock(&ph->common->eat);
	ph->meal_number++;
	ph->last_meal = get_current_time();
	pthread_mutex_unlock(&ph->common->eat);
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
