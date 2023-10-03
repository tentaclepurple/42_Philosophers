/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:14:14 by imontero          #+#    #+#             */
/*   Updated: 2023/09/29 17:03:40 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(size_t milliseconds, t_philos *ph)
{
	size_t	start;

	(void)ph;
	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		num;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= sign;
	return (num);
}

/* 
	Returns 1 if it´s digit. 0 otherwise
*/
int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
