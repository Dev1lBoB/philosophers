/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:56:39 by wpersimm          #+#    #+#             */
/*   Updated: 2021/04/20 10:38:47 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	ft_init(t_all *all, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		return (1);
	}
	ft_bzero(all, sizeof(t_all));
	all->size = ft_atoi(argv[1]);
	all->ttd = ft_atoi(argv[2]);
	all->tte = ft_atoi(argv[3]) * 1000;
	all->tts = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		all->flag = ft_atoi(argv[5]);
	if (argc == 6 && !all->flag)
		return (1);
	return (0);
}

void	ft_init_2(t_all *all)
{
	if (all->flag)
	{
		sem_unlink("syt");
		all->syt = sem_open("syt", O_CREAT, 0666, 0);
	}
	sem_unlink("sema");
	sem_unlink("dop");
	sem_unlink("dead");
	sem_unlink("dop2");
	sem_unlink("mussage");
	sem_unlink("monitor");
	sem_unlink("semaphore");
	all->semaphore = sem_open("semaphore", O_CREAT, 0666, all->size);
	all->sema = sem_open("sema", O_CREAT, 0666, 1);
	all->dop = sem_open("dop", O_CREAT, 0666, 1);
	all->dead = sem_open("dead", O_CREAT, 0666, 1);
	all->dop2 = sem_open("dop2", O_CREAT, 0666, 0);
	all->mussage = sem_open("mussage", O_CREAT, 0666, 1);
	all->monitor = sem_open("monitor", O_CREAT, 0666, 0);
	all->i = -1;
	gettimeofday(&all->tp, 0);
	all->time = all->tp.tv_sec * 1000 + all->tp.tv_usec / 1000;
}

int	ft_check(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				ft_putstr_fd("Error: argument\n", 2);
				return (1);
			}
		}
	}
	return (0);
}

void	ft_body(t_all *all, pthread_t *thread, pthread_t *td, pid_t **pid)
{
	while (++all->i < all->size)
	{
		(*pid)[all->i] = fork();
		if ((*pid)[all->i] != 0)
			continue ;
		pthread_create(td, NULL, ft_killer, all);
		pthread_create(thread, NULL, ft_problem, all);
		sem_wait(all->monitor);
		sem_post(all->monitor);
		pthread_detach(*td);
		pthread_detach(*thread);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	pthread_t	thread;
	pthread_t	td;
	pthread_t	td2;
	t_all		all;
	pid_t		*pid;

	if (ft_init(&all, argc, argv))
		return (1);
	if (ft_check(argv))
		return (1);
	ft_init_2(&all);
	pid = malloc(sizeof(pid_t) * all.size);
	if (!pid)
		return (1);
	all.i = -1;
	ft_body(&all, &thread, &td, &pid);
	if (all.flag)
		pthread_create(&td2, NULL, ft_sit, &all);
	while (all.i > -1)
	{
		waitpid(pid[all.i], 0, 0);
		--all.i;
	}
}
