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
	sem_unlink("/sem_prints");
	sem_unlink("/sem_forks");
	ph->sem_prints = sem_open("/sem_prints", O_CREAT, 0644, 1);
	ph->sem_forks = sem_open("/sem_forks", O_CREAT, 0644, ph[0].philo_amount);
	if (ph->sem_prints <= 0 || ph->sem_forks <= 0)
		ft_error_exit("Error: semaphore open error");	
}

void	*watcher_routine(void *pointer)
{
	t_philos	*ph;
	
	ph = (t_philos *)pointer;
	while (ph->ending_flag == CONTINUE)
	{
		usleep(100);
		if(get_current_time() - ph->last_meal >= ph->time_2_die)
		{
			ph->dead_flag = END;
			sem_wait(ph->sem_prints);
			printf("%zu %i %s\n", get_current_time() - ph->start_time, ph->philo_id, "died");
			ph->ending_flag = END;
			break ;
		}
		if (ph->max_meals != 0 && ph->meal_number >= ph->max_meals)
		{
			ph->ending_flag = END;
			break;
		}
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
		usleep(1000);
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
	sem_close(ph->sem_prints);
	sem_close(ph->sem_forks);
	sem_unlink("/sem_prints");
	sem_unlink("/sem_forks");
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
	printf("ph_am: %i, max_meals: %i, ph_id: %i\n", ph[0].philo_amount, ph[0].max_meals, ph[0].philo_id);
	while (i < ph[0].philo_amount)
	{
		ph->pid[i] = fork();
		printf("%i\n", ph->pid[i]);
		if (ph->pid[i] == -1)
			ft_error_exit("Fork error");
		if (ph->pid[i] == 0)
		{
			ph->philo_id = i;
			ph->last_meal = get_current_time();
			init_philos(ph);
		}
		i++;
	}
	return (0);
}
