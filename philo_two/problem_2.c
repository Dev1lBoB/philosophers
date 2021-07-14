/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:40:30 by wpersimm          #+#    #+#             */
/*   Updated: 2021/04/19 15:21:58 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int	ft_zero_1(t_all *all, int num)
{
	if (all->ded == 1 || (all->flag && all->sit >= all->flag))
		return (1);
	sem_wait(all->dop);
	sem_wait(all->semaphore);
	if (all->ded == 1 || (all->flag && all->sit >= all->flag))
		return (1);
	ft_message(all, num, "has taken a fork", "\033[35;m");
	sem_wait(all->semaphore);
	sem_post(all->dop);
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
	sem_post(all->semaphore);
	sem_post(all->semaphore);
	return (0);
}

void	*ft_zero(t_all *all, int num)
{
	while (1)
	{
		if (ft_zero_1(all, num))
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
