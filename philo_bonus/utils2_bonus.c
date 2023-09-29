/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:46:12 by imontero          #+#    #+#             */
/*   Updated: 2023/09/28 19:30:11 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*void	ft_prints(t_philos *ph, int i)
{
	size_t			time;

	pthread_mutex_lock(&ph->common->prnt);
	time = get_current_time() -  ph->c_start_time;
	if (i == PRNTDIED)
		printf("%s%7zu%s %s%3i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			RED, "died");
	if (check_end(ph) == END)
	{
		pthread_mutex_unlock(&ph->common->prnt);
		return ;
	}
	ft_prints_aux(ph, i, time);
	pthread_mutex_unlock(&ph->common->prnt);
}

void	ft_prints_aux(t_philos *ph, int i, size_t time)
{
	if (i == HASFORK)
		printf("%s%7zu%s %s%3i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			X, "has taken a fork");
	else if (i == PRNTEAT)
		printf("%s%7zu%s %s%3i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			GREEN, "is eating");
	else if (i == PRNTSLP)
		printf("%s%7zu%s %s%3i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			X, "is sleeping");
	else if (i == PRNTTHK)
		printf("%s%7zu%s %s%3i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			X, "is thinking");
}*/