/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:22:16 by imontero          #+#    #+#             */
/*   Updated: 2023/09/22 14:00:36 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *pointer)
{
	t_philos	*ph;

	ph = (t_philos *)pointer;
	//printf("id: %i", ph->philo_id);
	if (ph->philo_id % 2 != 0)
		ft_usleep(5);
	int i = 0;
	while(i < 4)
	{
		ft_eat(ph);
		ft_sleep(ph);
		ft_think(ph);
		i++;
	}
	return (pointer);
}

void	*watcher_routine(void *pointer)
{
	t_philos	*ph;
	//int i = 0;
	
	ph = (t_philos *)pointer;
	
	//int i = ph->philo_id;
	printf("el watchel\n");
	//while (i < ph->c_philo_amount)
	return (pointer);
}

void	init_threads(t_philos *ph, pthread_mutex_t *fork)
{
	pthread_t	the_watcher;
	int			i;

	i = 0;
	if (pthread_create(&the_watcher, NULL, &watcher_routine, ph) != 0)
		destroy_mutex("Error 0, capullo\n", ph, fork);
	while (i < ph[0].c_philo_amount)
	{
		if (pthread_create(&ph[i].thread, NULL, &philo_routine, &ph[i]) != 0)
			destroy_mutex("Error 1, payaso\n", ph, fork);
		i++;
	}
	i = 0;
	if (pthread_join(the_watcher, NULL) != 0)
		destroy_mutex("Error 3, sinsorgo\n", ph, fork);
	while (i < ph[0].c_philo_amount)
	{
		if (pthread_join(ph[i].thread, NULL) != 0)
			destroy_mutex("Error 2, tontolaba\n", ph, fork);
		i++;
	}
}

