/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:22:16 by imontero          #+#    #+#             */
/*   Updated: 2023/09/24 20:05:57 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *pointer)
{
	t_philos	*ph;

	ph = (t_philos *)pointer;
	//printf("id: %i", ph->philo_id);
	if (ph->philo_id % 2 != 0)
		ft_usleep(1);
	//int i = 0;
	while(ph->ending_flag == CONTINUE)
	{
		if (ph->ending_flag == END)
			return (0);
		ft_eat(ph);
		if (ph->ending_flag == END)
			return (0);
		ft_sleep(ph);
		if (ph->ending_flag == END)
			return (0);
		ft_think(ph);
		//i++;
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
		if (search_deads(ph) == 1)
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

