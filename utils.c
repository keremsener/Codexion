/* *********************************************************************** */
/*                                                                         */
/*                                                     :::      ::::::::   */
/* utils.c                                           :+:      :+:    :+:   */
/*                                                 +:+ +:+         +:+     */
/* By: ksener <ksener@student.42kocaeli.com.tr   +#+  +:+       +#+        */
/*                                             +#+#+#+#+#+   +#+           */
/* Created: 2026/11/25 13:33:08 by ksener          #+#    #+#              */
/* Updated: 2026/11/25 14:22:02 by ksener          ###   ########.fr       */
/*                                                                         */
/* *********************************************************************** */

#include "codexion.h"


int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	result;

	result = 0;
	minus = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13)
		|| str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -minus;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * minus);
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	is_sim_over(t_sim *sim)
{
	int	over;

	pthread_mutex_lock(&sim->sim_mutex);
	over = sim->is_over;
	pthread_mutex_unlock(&sim->sim_mutex);
	return (over);
}


void	smart_sleep(long duration_ms, t_sim *sim)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start < duration_ms)
	{
		if (is_sim_over(sim))
			break ;
		usleep(500);
	}
}

void	print_status(t_sim *sim, int coder_id, char *status, int is_burnout)
{
	pthread_mutex_lock(&sim->print_mutex);
	if (!is_sim_over(sim) || is_burnout)
		printf("%ld %d %s\n", get_time_ms() - sim->start_time, coder_id, status);
	pthread_mutex_unlock(&sim->print_mutex);
}