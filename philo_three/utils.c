/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:48:18 by wpersimm          #+#    #+#             */
/*   Updated: 2021/04/19 21:57:53 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		c;
	int		num;
	int		dig;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	num = n;
	c = 1;
	while (num / 10 != 0)
	{
		num /= 10;
		c *= 10;
	}
	while (c != 0)
	{
		dig = n / c + 48;
		write(fd, &dig, 1);
		n %= c;
		c /= 10;
	}
}

void	ft_bzero(void *b, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = 0;
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long int		res;

	res = 0;
	i = -1;
	while (str[++i])
		res = res * 10 + str[i] - 48;
	return ((int)res);
}
