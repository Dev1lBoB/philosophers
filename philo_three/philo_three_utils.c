/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:20:59 by wpersimm          #+#    #+#             */
/*   Updated: 2021/04/20 00:59:23 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_usleep(int time, t_all *all)
{
	long long	time2;
	long long	time1;

	gettimeofday(&all->tp3, 0);
	time2 = all->tp3.tv_sec * 1000 + all->tp3.tv_usec / 1000;
	time1 = time / 1000 + all->tp3.tv_sec * 1000 + all->tp3.tv_usec / 1000;
	while (time2 < time1)
	{
		usleep(100);
		gettimeofday(&all->tp3, 0);
		time2 = all->tp3.tv_sec * 1000 + all->tp3.tv_usec / 1000;
	}
}

void	ft_message(t_all *all, int num, char *str, char *color)
{
	sem_wait(all->mussage);
	if (all->havka == 1 && all->et <= all->flag)
		++all->et;
	if (all->et == all->flag)
	{
		sem_post(all->syt);
		++all->et;
	}
	if (all->ded == 1)
	{
		sem_post(all->mussage);
		return ;
	}
	ft_putstr_fd(color, 1);
	gettimeofday(&all->tp, 0);
	ft_putnbr_fd(all->tp.tv_sec * 1000 + \
			all->tp.tv_usec / 1000 - all->time, 1);
	ft_putstr_fd(" philo[", 1);
	ft_putnbr_fd(num + 1, 1);
	ft_putstr_fd("] ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	sem_post(all->mussage);
}

void	ft_message_2(t_all *all, int num, char *str, char *color)
{
	sem_wait(all->mussage);
	ft_putstr_fd(color, 1);
	gettimeofday(&all->tp, 0);
	ft_putnbr_fd(all->tp.tv_sec * 1000 + \
			all->tp.tv_usec / 1000 - all->time, 1);
	ft_putstr_fd(" philo[", 1);
	ft_putnbr_fd(num + 1, 1);
	ft_putstr_fd("] ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
}
