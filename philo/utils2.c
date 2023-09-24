/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:46:12 by imontero          #+#    #+#             */
/*   Updated: 2023/09/24 20:54:27 by imontero         ###   ########.fr       */
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
	if (i == PRNTDIED)
		printf("%s%7zu%s %s%2i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			RED, "died");
	if (ph->ending_flag == END)
		return ;
	if (i == HASFORK)
		printf("%s%7zu%s %s%2i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			X, "has taken a fork");
	else if (i == PRNTEAT)
		printf("%s%7zu%s %s%2i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			GREEN, "is eating");
	else if (i == PRNTSLP)
		printf("%s%7zu%s %s%2i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			X, "is sleeping");
	else if (i == PRNTTHK)
		printf("%s%7zu%s %s%2i%s %s\n", CYAN, time, X, BOLD, ph->philo_id + 1,
			X, "is thinking");
	pthread_mutex_unlock(&prnt);
	pthread_mutex_destroy(&prnt);
}

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = ptr;
	i = 0;
	while (i < n)
	{
		s[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
