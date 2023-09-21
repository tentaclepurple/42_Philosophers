/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:21:06 by imontero          #+#    #+#             */
/*   Updated: 2023/09/21 16:17:26 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av)
{
	int	i;
	int j;
	
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) || ft_atoi(av[i]) <= 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	fill_common_data(int ac, char **av, t_philos **ph)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		ph[i]->c_start_time = get_current_time();
		ph[i]->c_philo_amount = ft_atoi(av[1]);
		ph[i]->c_time_2_die = ft_atoi(av[2]);
		ph[i]->c_time_2_eat = ft_atoi(av[3]);
		ph[i]->c_time_2_slp = ft_atoi(av[4]);
		ph[i]->philo_id = i + 1;
		ph[i]->meals = 0;
		ph[i]->dead_flag = ALIVE;
		if (ac == 6)
			ph[i]->c_max_meals = ft_atoi(av[5]);
		i++;
	}	
}
