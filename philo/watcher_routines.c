/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:50:57 by imontero          #+#    #+#             */
/*   Updated: 2023/09/24 19:57:35 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	search_deads(t_philos *ph)
{
	int	i;

	i = 0;
	while (i < ph[i].c_philo_amount)
	{
		//printf("i: %i id: %i, eating: %i, %zu, %zu, %zu, %zu\n", i, ph[i].philo_id, ph[i].eating_flag, get_current_time(), ph[i].last_meal, get_current_time() - ph[i].last_meal, ph[i].c_time_2_die);
		if (get_current_time() - ph[i].last_meal >= ph[i].c_time_2_die &&
			ph[i].eating_flag == NOTEATING)
		{
			ft_ending(ph);
			ft_prints(ph, PRNTDIED);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_ending(t_philos *ph)
{
	int	i;

	i = 0;
	while (i < ph[0].c_philo_amount)
	{
		ph[i].ending_flag = END;
		i++;
	}
}