/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:46:12 by imontero          #+#    #+#             */
/*   Updated: 2023/09/24 11:40:29 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	ft_prints(t_philos *ph, int i)
{
	size_t			time;
	pthread_mutex_t	prnt;

	pthread_mutex_init(&prnt, NULL);
	pthread_mutex_lock(&prnt);
	time = get_current_time() -  ph->c_start_time;
	if (i == HASFORK)
		printf("%s%7zu%s %s%2i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			X, "has taken a fork");
	else if (i == ISEATING)
		printf("%s%7zu%s %s%2i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			GREEN, "is eating");
	else if (i == ISSLEEPING)
		printf("%s%7zu%s %s%2i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			X, "is sleeping");
	else if (i == ISTHINKING)
		printf("%s%7zu%s %s%2i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			X, "is thinking");
	else
	printf("%s%7zu%s %s%2i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			RED, "has died");
	pthread_mutex_unlock(&prnt);
	pthread_mutex_destroy(&prnt);
}

/*void	ft_prints(t_philos *ph, char *s)
{
	size_t			time;
	pthread_mutex_t	prnt;

	pthread_mutex_init(&prnt, NULL);
	pthread_mutex_lock(&prnt);
	time = get_current_time() - ph->c_start_time;
	printf("%7zu %3i %s\n", time, ph->philo_id + 1, s);
	pthread_mutex_unlock(&prnt);
	pthread_mutex_destroy(&prnt);
}*/