/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:46:12 by imontero          #+#    #+#             */
/*   Updated: 2023/09/29 17:18:10 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_prints(t_philos *ph, char *str)
{
	sem_wait(ph->sem_prints);
	if (ph->ending_flag == CONTINUE)
		printf("%zu %d %s\n", get_current_time() - ph->start_time, ph->philo_id + 1, str);
	sem_post(ph->sem_prints);
}

int	check_args(char **av)
{
	int	i;
	int	j;

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

void	ft_error_exit(char *str)
{
	printf("%s\n", str);
	exit (-1);
}
