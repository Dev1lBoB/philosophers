/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:37:49 by wpersimm          #+#    #+#             */
/*   Updated: 2021/04/20 11:25:08 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*ft_problem(void *val)
{
	t_all	*all;
	int		num;

	all = (t_all *)val;
	num = all->i;
	all->victims = all->time;
	sem_post(all->dop2);
	return (ft_zero(all, num));
}

int	ft_killer_1(t_all *all, int j)
{
	gettimeofday(&all->tp2, 0);
	if (all->havka != 1)
	{
		if (all->tp2.tv_sec * 1000 + all->tp2.tv_usec / 1000 - \
				all->victims - all->ttd - 2 >= 0)
		{
			sem_wait(all->dead);
			ft_message_2(all, all->i, "died", "\033[31;m");
			all->ded = 1;
			j = -1;
			sem_post(all->monitor);
			return (1);
		}
	}
	return (0);
}

void	*ft_killer(void *val)
{
	t_all	*all;
	int		j;

	all = (t_all *)val;
	sem_wait(all->dop2);
	while (1)
	{
		j = -1;
		if (ft_killer_1(all, j))
			return (0);
	}
}

void	*ft_sit(void *val)
{
	t_all	*all;
	int		j;

	all = (t_all *)val;
	j = -1;
	while (++j < all->size)
		sem_wait(all->syt);
	sem_wait(all->mussage);
	sem_post(all->monitor);
	return (0);
}
