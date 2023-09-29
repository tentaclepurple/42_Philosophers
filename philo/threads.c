/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:22:16 by imontero          #+#    #+#             */
/*   Updated: 2023/09/27 12:04:55 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *pointer)
{
	t_philos	*ph;

	ph = (t_philos *)pointer;
	if (ph->philo_id % 2 != 0)
		ft_usleep(1);
	while (check_end(ph) == CONTINUE)
	{
		ft_eat(ph);
		ft_sleep(ph);
		ft_think(ph);
	}
	return (pointer);
}

void	*watcher_routine(void *pointer)
{
	t_philos	*ph;

	ph = (t_philos *)pointer;
	ft_usleep(2);
	while (1)
	{
		if (search_deads(ph) == 1 || check_every1_ate(ph) == 1)
			break ;
	}
	return (pointer);
}

void	init_threads(t_philos *ph, pthread_mutex_t *fork)
{
	pthread_t	the_watcher;
	int			i;

	i = 0;
	if (pthread_create(&the_watcher, NULL, &watcher_routine, ph) != 0)
		destroy_mutex("Error\n", ph, fork);
	while (i < ph[0].c_philo_amount)
	{
		if (pthread_create(&ph[i].thread, NULL, &philo_routine, &ph[i]) != 0)
			destroy_mutex("Error\n", ph, fork);
		i++;
	}
	i = 0;
	if (pthread_join(the_watcher, NULL) != 0)
		destroy_mutex("Error\n", ph, fork);
	while (i < ph[0].c_philo_amount)
	{
		if (pthread_join(ph[i].thread, NULL) != 0)
			destroy_mutex("Error\n", ph, fork);
		i++;
	}
}

int	check_end(t_philos *ph)
{
	pthread_mutex_lock(&ph->common->end);
	if (ph->ending_flag == CONTINUE)
	{
		pthread_mutex_unlock(&ph->common->end);
		return (CONTINUE);
	}
	pthread_mutex_unlock(&ph->common->end);
	return (END);
}
