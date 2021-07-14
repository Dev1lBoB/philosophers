/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:37:49 by wpersimm          #+#    #+#             */
/*   Updated: 2021/04/19 15:23:22 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*ft_problem(void *val)
{
	t_all	*all;
	int		num;

	all = (t_all *)val;
	sem_wait(all->sema);
	++all->i;
	num = all->i;
	gettimeofday(&all->tp[num], 0);
	all->timer[num] = all->tp[num].tv_sec * 1000 + all->tp[num].tv_usec / 1000;
	sem_post(all->sema);
	return (ft_zero(all, num));
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
					sem_post(all->semaphore);
				sem_post(all->dop);
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
			sem_wait(all->sema);
			j = -1;
			while (++j < all->size)
				if (all->et[j] < all->flag)
					break ;
			if (j == all->size)
			{
				all->ded = 1;
				return (0);
			}
			sem_post(all->sema);
		}
		if (ft_killer_1(all, j))
			return (0);
	}
}
