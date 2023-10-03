/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:03:26 by imontero          #+#    #+#             */
/*   Updated: 2023/09/29 19:01:50 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	fill_data(int ac, char **av, t_philos *ph)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		ph->last_meal = get_current_time();
		ph->start_time = get_current_time();
		ph->philo_amount = ft_atoi(av[1]);
		ph->time_2_die = ft_atoi(av[2]);
		ph->time_2_eat = ft_atoi(av[3]);
		ph->time_2_slp = ft_atoi(av[4]);
		if (ac == 6)
			ph->max_meals = ft_atoi(av[5]);
		i++;
	}
	open_close_sems(ph, 1);
}

void	*watcher_routine(void *pointer)
{
	t_philos	*ph;

	ph = (t_philos *)pointer;
	while (ph->ending_flag == CONTINUE)
	{
		usleep(100);
		if (check_dead(ph))
		{
			one_died(ph);
			break ;
		}
		sem_wait(ph->sem_meals);
		if (ph->max_meals != 0 && ph->meal_number >= ph->max_meals)
		{
			watcher_aux(ph);
			sem_post(ph->sem_meals);
			break ;
		}
		sem_post(ph->sem_meals);
	}
	if (ph->dead_flag)
		exit (1);
	else
		exit (0);
}

void	init_philos(t_philos *ph)
{
	if (pthread_create(&ph->thread, NULL, &watcher_routine, ph))
		ft_error_exit("Thread error");
	if (ph->philo_id % 2 != 0)
		usleep(10);
	while (1)
	{
		eating_aux(ph);
		ft_prints(ph, "is sleeping");
		ft_usleep(ph->time_2_slp, ph);
		ft_prints(ph, "is thinking");
	}
	if (pthread_join(ph->thread, NULL))
		ft_error_exit("Join thread error");
}

void	exit_philo(t_philos *ph)
{
	int		i;
	int		status;

	i = 0;
	while (i < ph->philo_amount)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < ph->philo_amount)
				kill(ph->pid[i], SIGKILL);
			break ;
		}
		i++;
	}
	open_close_sems(ph, 0);
}

int	main(int ac, char **av)
{
	t_philos	ph;
	int			i;

	if (ac < 5 || ac > 6)
		return (printf("Invalid argument number\n"), -1);
	if (check_args(av))
		return (printf("Invalid arguments\n"), -1);
	memset(&ph, 0, sizeof(t_philos));
	fill_data(ac, av, &ph);
	i = 0;
	while (i < ph.philo_amount)
	{
		ph.pid[i] = fork();
		if (ph.pid[i] == -1)
			ft_error_exit("Fork error");
		if (ph.pid[i] == 0)
		{
			ph.philo_id = i;
			ph.last_meal = get_current_time();
			init_philos(&ph);
		}
		i++;
	}
	exit_philo(&ph);
	return (0);
}
