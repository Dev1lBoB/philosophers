/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:23:08 by wpersimm          #+#    #+#             */
/*   Updated: 2021/04/18 15:58:38 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_all
{
	pthread_mutex_t	*mutex;
	pthread_mutex_t	muta;
	pthread_mutex_t	mussage;
	struct timeval	*tp;
	struct timeval	tp2;
	struct timeval	tp3;
	int				ttd;
	int				tte;
	int				tts;
	long long		time;
	long long		*timer;
	long long		*victims;
	int			 	*havka;
	int				ded;
	int				*et;
	int				sit;
	int				flag;
	int				i;
	int				size;
}				t_all;

void	ft_usleep(int time, t_all *all);
void	ft_message(t_all *all, int num, char *str, char *color);
void	ft_message_2(t_all *all, int num, char *str, char *color);
void	*ft_killer(void *val);
void	*ft_problem(void *val);
void	*ft_odd(t_all *all, int num);
void	*ft_even(t_all *all, int num);
void	*ft_zero(t_all *all, int num);
void	ft_bzero(void *mem, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_killer_1(t_all *all, int j);
int		ft_atoi(const char *str);

#endif
