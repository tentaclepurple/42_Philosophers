/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:03:26 by imontero          #+#    #+#             */
/*   Updated: 2023/09/29 13:50:55 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	fill_data(int ac, char **av, t_philos *ph)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		ph[i].last_meal = get_current_time();
		ph[0].start_time = get_current_time();
		ph[0].philo_amount = ft_atoi(av[1]);
		ph[0].time_2_die = ft_atoi(av[2]);
		ph[0].time_2_eat = ft_atoi(av[3]);
		ph[0].time_2_slp = ft_atoi(av[4]);
		if (ac == 6)
			ph[0].max_meals = ft_atoi(av[5]);
		i++;
	}
	ph->sem_prints = sem_open("/sem_prints", O_CREAT, 0644, 1);
	ph->sem_forks = sem_open("/sem_prints", O_CREAT, 0644, ph->philo_amount);
	if (ph->sem_prints <= 0 || ph->sem_forks <= 0)
		ft_error_exit("Error: semaphore open error");	
}
void	*watcher_routine(void *pointer)
{
	t_philos	*ph;

	while (ph->ending_flag == CONTINUE)
	{
		usleep(100);
		if(get_current_time() - ph->last_meal >= ph->time_2_die)
		{
			ph->
		}
	}
}
void	ft_prints(t_philos *ph, char *str)
{
	sem_wait(ph->sem_prints);
	if (ph->ending_flag == CONTINUE)
		printf("%zu %d %s\n", get_current_time() - ph->start_time, ph->philo_id + 1, str);
	sem_post(ph->sem_prints);
}

void	init_philos(t_philos *ph)
{
	if (pthread_create(&ph->thread, NULL, &watcher_routine, ph))
		ft_error_exit("Thread error");
	if (ph->philo_id % 2 == 0)
		usleep(10);
	while (1)
	{
		sem_wait(ph->sem_forks);
		ft_prints(ph, "has taken a fork");
		sem_wait(ph->sem_forks);
		ft_prints(ph, "has taken a fork");
		ft_prints(ph, "is eating");
		ft_usleep(ph->time_2_eat);
		ph->last_meal = get_current_time();
		sem_post(ph->sem_forks);
		sem_post(ph->sem_forks);
		ph->meal_number++;
		ft_prints(ph, "is sleeping");
		ft_usleep(ph->time_2_slp);
		philo_print(ph, "is thinking");
	}
	if (pthread_join(ph->thread, NULL))
		ft_error_exit("Join thread error");
}

int	main(int ac, char **av)
{
	t_philos	ph[PHILMAX];
	int			i;

	if (ac < 5 || ac > 6)
		return (printf("Invalid argument number\n"), -1);
	if (check_args(av))
		return (printf("Invalid arguments\n"), -1);
	memset(&ph, 0, sizeof(t_philos));
	fill_data(ac, av, ph);
	i = 0;
	while (i < ph[0].philo_amount)
	{
		ph->pid[i] = fork();
		if (ph->pid[i] == -1)
			ft_error_exit("Fork error");
		if (ph->pid[i] == 0)
		{
			ph->philo_id = i;
			ph->last_meal = get_current_time();
			init_philos(ph);
		}
	//philos
	}
	return (0);
}
