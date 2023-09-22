/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:03:26 by imontero          #+#    #+#             */
/*   Updated: 2023/09/22 13:31:37 by imontero         ###   ########.fr       */
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
	if (ft_atoi(av[1]) > PHILMAX)
		return (-1);
	return (0);
}

void	fill_data(int ac, char **av, t_philos *ph, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_init(&fork[i], NULL);
		ph[i].c_start_time = get_current_time();
		ph[i].c_philo_amount = ft_atoi(av[1]);
		ph[i].c_time_2_die = ft_atoi(av[2]);
		ph[i].c_time_2_eat = ft_atoi(av[3]);
		ph[i].c_time_2_slp = ft_atoi(av[4]);
		ph[i].philo_id = i;
		ph[i].meals = 0;
		ph[i].dead_flag = ALIVE;
		if (ac == 6)
			ph[i].c_max_meals = ft_atoi(av[5]);
		ph[i].fork_l = &fork[i];
		if (i == ph[0].c_philo_amount - 1)
			ph[i].fork_r = &fork[0];
		else
			ph[i].fork_r = &fork[i + 1];
		i++;
	}	
}

int	main(int ac, char **av)
{
	t_philos	ph[PHILMAX];
	pthread_mutex_t	fork[PHILMAX];

	if (ac < 5 || ac > 6)
		return(printf("Invalid argument number\n"), -1);
	if (check_args(av))
		return(printf("Invalid arguments\n"), -1);
	printf("todo ok, payaso\n");
	fill_data(ac, av, ph, fork);
	init_threads(ph, fork);
	

	return (0);
}


	/*while (i < ph[0].c_philo_amount)
	{
		printf(" i: %i\n id: %i\n meals: %i\n d_flag: %i\n philo_amount: %i\n start_time: %zu\n time2d: %zu\n time2e: %zu\n time2s: %zu\n maxmeals: %i\n\n\n"\
		, i, ph[i].philo_id, ph[i].meals, ph[i].dead_flag, ph[i].c_philo_amount, ph[i].c_start_time, ph[i].c_time_2_die, \
		ph[i].c_time_2_eat, ph[i].c_time_2_slp, ph[i].c_max_meals);
		i++;
	}*/