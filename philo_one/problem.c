/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:37:49 by wpersimm          #+#    #+#             */
/*   Updated: 2021/04/18 15:38:44 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	ft_odd_1(t_all *all, int num)
{
	if (all->ded == 1 || (all->flag && all->sit >= all->flag))
		return (1);
	pthread_mutex_lock(&all->mutex[num - 1]);
	if (all->ded == 1 || (all->flag && all->sit >= all->flag))
		return (1);
	ft_message(all, num, "has taken a fork", "\033[35;m");
	pthread_mutex_lock(&all->mutex[num]);
	if (all->ded == 1 || (all->flag && all->sit >= all->flag))
		return (1);
	ft_message(all, num, "has taken a fork", "\033[35;m");
	all->havka[num] = 1;
	all->victims[num] = all->tp[num].tv_sec * 1000 + \
						all->tp[num].tv_usec / 1000;
	if (all->ded == 1 || (all->flag && all->sit >= all->flag))
		return (1);
	ft_message(all, num, "is eating", "\033[32;m");
	if (all->flag && all->sit >= all->flag)
		return (1);
	ft_usleep(all->tte, all);
	all->havka[num] = 0;
	pthread_mutex_unlock(&all->mutex[num]);
	pthread_mutex_unlock(&all->mutex[num - 1]);
	return (0);
}

void	*ft_odd(t_all *all, int num)
{
	while (1)
	{
		if (ft_odd_1(all, num))
			return (0);
		if (all->ded == 1 || (all->flag && all->sit >= all->flag))
			return (0);
		ft_message(all, num, "is sleeping", "\033[33;m");
		ft_usleep(all->tts, all);
		if (all->ded == 1 || (all->flag && all->sit >= all->flag))
			return (0);
		ft_message(all, num, "is thinking", "\033[36;m");
	}
	return (0);
}

void	*ft_problem(void *val)
{
	t_all	*all;
	int		num;

	all = (t_all *)val;
	pthread_mutex_lock(&all->muta);
	++all->i;
	num = all->i;
	gettimeofday(&all->tp[num], 0);
	all->timer[num] = all->tp[num].tv_sec * 1000 + all->tp[num].tv_usec / 1000;
	pthread_mutex_unlock(&all->muta);
	if (num == 0)
		return (ft_zero(all, num));
	else if (num % 2 == 0)
		return (ft_even(all, num));
	return (ft_odd(all, num));
}

int	ft_killer_1(t_all *all, int j)
{
	gettimeofday(&all->tp2, 0);
	j = -1;
	while (++j < all->size)
	{
		if (all->havka[j] != 1)
		{
			if (all->tp2.tv_sec * 1000 + all->tp2.tv_usec / 1000 - \
					all->victims[j] - all->ttd - 2 >= 0)
			{
				ft_message_2(all, j, "died", "\033[31;m");
				all->ded = 1;
				j = -1;
				while (++j < all->size)
					pthread_mutex_unlock(&all->mutex[j]);
				return (1);
			}
		}
	}
	return (0);
}

void	*ft_killer(void *val)
{
	t_all	*all;
	int		j;

	all = (t_all *)val;
	while (1)
	{
		if (all->flag)
		{
			pthread_mutex_lock(&all->muta);
			j = -1;
			while (++j < all->size)
				if (all->et[j] < all->flag)
					break ;
			if (j == all->size)
			{
				all->ded = 1;
				return (0);
			}
			pthread_mutex_unlock(&all->muta);
		}
		if (ft_killer_1(all, j))
			return (0);
	}
}
