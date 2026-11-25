/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:21:17 by ksener            #+#    #+#             */
/*   Updated: 2026/11/25 14:55:00 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>
#include <limits.h>

static int	is_valid_number(char *str)
{
	long	res;
	int		i;

	if (!str || !str[0])
		return (-1);
	i = 0;
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (-1);
	res = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = (res * 10) + (str[i] - '0');
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	return (0);
}

static int	scheduler_checker(char *str)
{
	char	*choice1;
	char	*choice2;
	int		i;

	choice1 = "fifo";
	choice2 = "edf";
	i = 0;
	while (str[i] && choice1[i] && str[i] == choice1[i])
		i++;
	if (str[i] == '\0' && choice1[i] == '\0')
		return (0);
	i = 0;
	while (str[i] && choice2[i] && str[i] == choice2[i])
		i++;
	if (str[i] == '\0' && choice2[i] == '\0')
		return (0);
	return (-1);
}

static int	check_all_args(char **argv)
{
	int	i;

	i = 1;
	while (i <= 7)
	{
		if (is_valid_number(argv[i]) == -1)
			return (-1);
		i++;
	}
	if (scheduler_checker(argv[8]) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	number_of_coders;
	int	time_to_burnout;
	int	time_to_compile;
	int	time_to_debug;
	int	time_to_refactor;
	int	number_of_compiles_required;
	int	dongle_cooldown;

	if (argc != 9 || check_all_args(argv) == -1)
		return (1);
	number_of_coders = ft_atoi(argv[1]);
	time_to_burnout = ft_atoi(argv[2]);
	time_to_compile = ft_atoi(argv[3]);
	time_to_debug = ft_atoi(argv[4]);
	time_to_refactor = ft_atoi(argv[5]);
	number_of_compiles_required = ft_atoi(argv[6]);
	dongle_cooldown = ft_atoi(argv[7]);
	if (number_of_coders <= 0 || number_of_compiles_required < 1
		|| time_to_burnout <= 0 || time_to_compile <= 0
		|| time_to_debug <= 0 || time_to_refactor <= 0 || dongle_cooldown < 0)
		return (1);
	printf("Coders: %d | Burnout: %d | Compiles: %d | Cooldown: %d | Sched: %s\n",
		number_of_coders, time_to_burnout, number_of_compiles_required,
		dongle_cooldown, argv[8]);
	return (0);
}