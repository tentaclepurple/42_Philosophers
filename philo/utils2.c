/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:46:12 by imontero          #+#    #+#             */
/*   Updated: 2023/09/22 13:50:45 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_prints(t_philos *ph, char *s)
{
	size_t			time;
	pthread_mutex_t	prnt;

	pthread_mutex_init(&prnt, NULL);
	pthread_mutex_lock(&prnt);
	time = get_current_time() - ph->c_start_time;
	printf("%7zu %3i %s\n", time, ph->philo_id + 1, s);
	pthread_mutex_unlock(&prnt);
	pthread_mutex_destroy(&prnt);
}
