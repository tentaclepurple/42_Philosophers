/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:50:57 by imontero          #+#    #+#             */
/*   Updated: 2023/09/27 13:07:22 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	search_deads(t_philos *ph)
{
	int	i;

	i = 0;
	while (i < ph[i].c_philo_amount)
	{
		pthread_mutex_lock(&ph->common->eat);
		if (get_current_time() - ph[i].last_meal >= ph[i].c_time_2_die
			&& ph[i].eating_flag == NOTEATING)
		{
			ft_ending(ph);
			ft_prints(ph, PRNTDIED);
			pthread_mutex_unlock(&ph->common->eat);
			return (1);
		}
		i++;
		pthread_mutex_unlock(&ph->common->eat);
	}
	return (0);
}

int	check_every1_ate(t_philos *ph)
{
	int	i;
	int	meal_num_reached;

	i = 0;
	meal_num_reached = 0;
	if (ph[0].c_max_meals == 0)
		return (0);
	while (i < ph[0].c_philo_amount)
	{
		pthread_mutex_lock(&ph->common->eat);
		if (ph[i].meal_number >= ph[0].c_max_meals)
			meal_num_reached++;
		i++;
		pthread_mutex_unlock(&ph->common->eat);
	}
	if (meal_num_reached == ph[0].c_philo_amount)
	{
		ft_ending(ph);
		return (1);
	}
	return (0);
}

void	ft_ending(t_philos *ph)
{
	int	i;

	i = 0;
	while (i < ph[0].c_philo_amount)
	{
		pthread_mutex_lock(&ph->common->end);
		ph[i].ending_flag = END;
		i++;
		pthread_mutex_unlock(&ph->common->end);
	}
}

/*int	check_eat(t_philos *ph)
{
	if (ph->ending_flag == CONTINUE)
	{
		return (CONTINUE);
	}

	return (END);
}*/