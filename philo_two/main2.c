/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:56:39 by wpersimm          #+#    #+#             */
/*   Updated: 2021/04/19 22:16:22 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	ft_init_1(t_all *all, pthread_t **thread)
{
	*thread = malloc(sizeof(pthread_t) * all->size);
	if (!*thread)
		return (1);
	all->tp = malloc(sizeof(struct timeval) * all->size);
	if (!all->tp)
		return (1);
	all->victims = malloc(sizeof(long long) * all->size);
	if (!all->victims)
		return (1);
	all->timer = malloc(sizeof(long long) * all->size);
	if (!all->timer)
		return (1);
	all->havka = malloc(sizeof(int) * all->size);
	if (!all->havka)
		return (1);
	all->et = malloc(sizeof(int) * all->size);
	if (!all->et)
		return (1);
	return (0);
}

int	ft_init(t_all *all, int argc, char **argv, pthread_t **thread)
{
	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		return (1);
	}
	ft_bzero(all, sizeof(t_all));
	all->size = ft_atoi(argv[1]);
	if (ft_init_1(all, thread))
		return (1);
	ft_bzero(all->havka, sizeof(int) * all->size);
	ft_bzero(all->et, sizeof(int) * all->size);
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
	int	j;

	sem_unlink("sema");
	sem_unlink("dop");
	sem_unlink("mussage");
	sem_unlink("semaphore");
	all->semaphore = sem_open("semaphore", O_CREAT, 0666, all->size);
	all->sema = sem_open("sema", O_CREAT, 0666, 1);
	all->dop = sem_open("dop", O_CREAT, 0666, 1);
	all->mussage = sem_open("mussage", O_CREAT, 0666, 1);
	j = -1;
	all->i = -1;
	gettimeofday(&all->tp[0], 0);
	all->time = all->tp[0].tv_sec * 1000 + all->tp[0].tv_usec / 1000;
	j = -1;
	while (++j < all->size)
		all->victims[j] = all->time;
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

int	main(int argc, char **argv)
{
	pthread_t	*thread;
	pthread_t	td;
	int			j;
	t_all		all;

	if (ft_init(&all, argc, argv, &thread))
		return (1);
	if (ft_check(argv))
		return (1);
	ft_init_2(&all);
	j = -1;
	while (++j < all.size)
		pthread_create(&thread[j], NULL, ft_problem, &all);
	pthread_create(&td, NULL, ft_killer, &all);
	j = -1;
	pthread_join(td, NULL);
	while (++j < all.size)
		pthread_join(thread[j], 0);
}
