/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:03:26 by imontero          #+#    #+#             */
/*   Updated: 2023/09/21 16:09:42 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philos	ph[PHILMAX];

	if (ac < 5 || ac > 6)
		return(printf("Invalid argument number\n"), -1);
	if (check_args(av))
		return(printf("Invalid arguments\n"), -1);
	printf("todo ok, payaso");
	fill_common_data(ac, av, &ph);
	int i = 0;
	while (i < ph[0].c_philo_amount)
	{
		printf("i: %i\n id: %i\n meals: %i\n d_flag: %i\n start_time: %zu\n time2d: %zu\n time2e: %zu\n time2s: %zu\n maxmeals: %i\n\n\n", i, ph[i].philo_id, ph[i].meals, ph[i].dead_flag, ph[i].c_start_time, ph[i].c_time_2_die, ph[i].c_time_2_eat, ph[i].c_time_2_slp, ph[i].c_max_meals);
		i++;
	}
	
	return (0);
}
