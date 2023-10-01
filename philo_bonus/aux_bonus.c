/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:12:01 by imontero          #+#    #+#             */
/*   Updated: 2023/10/01 19:12:01 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*
	Open or closes semaphores depending on the flag sent 
	1- open
	0- close
*/
void	open_close_sems(t_philos *ph, int i)
{
	if (i == 0)
	{
		sem_close(ph->sem_meals);
		sem_close(ph->sem_lmeal);
		sem_close(ph->sem_prints);
		sem_close(ph->sem_forks);
		sem_close(ph->sem_end);
		sem_unlink("/sem_lmeal");
		sem_unlink("/sem_prints");
		sem_unlink("/sem_forks");
		sem_unlink("/sem_meals");
		sem_unlink("/sem_end");
		return ;
	}
	sem_unlink("/sem_prints");
	sem_unlink("/sem_forks");
	sem_unlink("/sem_meals");
	sem_unlink("/sem_lmeal");
	sem_unlink("/sem_end");
	ph->sem_prints = sem_open("/sem_prints", O_CREAT, 0644, 1);
	ph->sem_forks = sem_open("/sem_forks", O_CREAT, 0644, ph->philo_amount);
	ph->sem_meals = sem_open("/sem_meals", O_CREAT, 0644, 1);
	ph->sem_lmeal = sem_open("/sem_lmeal", O_CREAT, 0644, 1);
	ph->sem_end = sem_open("/sem_end", O_CREAT, 0644, 1);
}

int	check_dead(t_philos *ph)
{
	size_t	elapsed_time;

	sem_wait(ph->sem_lmeal);
	elapsed_time = get_current_time() - ph->last_meal;
	sem_post(ph->sem_lmeal);
	if (elapsed_time >= ph->time_2_die)
		return (1);
	else
		return (0);
}

void	eating_aux(t_philos *ph)
{
	sem_wait(ph->sem_forks);
	ft_prints(ph, "has taken a fork");
	sem_wait(ph->sem_forks);
	ft_prints(ph, "has taken a fork");
	ft_prints(ph, "is eating");
	ft_usleep(ph->time_2_eat, ph);
	sem_wait(ph->sem_lmeal);
	ph->last_meal = get_current_time();
	sem_post(ph->sem_lmeal);
	sem_post(ph->sem_forks);
	sem_post(ph->sem_forks);
	sem_wait(ph->sem_meals);
	ph->meal_number++;
	sem_post(ph->sem_meals);
}

/* 
	just to keep watcher routine under 25 lines ¬¬
*/
void	one_died(t_philos *ph)
{
	ph->dead_flag = END;
	printf("%s%7zu%s %s%3i%s %s\n", CYAN, get_current_time() \
		- ph->start_time, X, BOLD, ph->philo_id + 1, RED, "died");
	sem_wait(ph->sem_end);
	ph->ending_flag = END;
	sem_post(ph->sem_end);
}
