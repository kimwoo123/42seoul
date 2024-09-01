/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:43:51 by wooseoki          #+#    #+#             */
/*   Updated: 2023/06/10 18:48:30 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_time	ft_aton(const char *str)
{
	size_t			index;
	t_time			acc;

	index = 0;
	if (str[index] == '+')
		index++;
	acc = 0;
	while (str[index])
	{
		acc = acc * 10 + (str[index] - '0');
		if (acc >= INT_LIMIT)
			return (0);
		index++;
	}
	return (acc);
}

static int	set_fork(t_data *data)
{
	int	index;
	int	head_count;

	head_count = data->number_of_philos;
	data->forks = (t_fork *)malloc(sizeof(t_fork) * head_count);
	if (data->forks == NULL)
		return (FAIL);
	index = 0;
	while (index < head_count)
	{
		if (pthread_mutex_init(&(data->forks[index].key), NULL) != 0)
			return (FAIL);
		data->forks[index].state = DOWN;
		index++;
	}
	return (SUCCESS);
}

static int	set_data(t_data *data, char **argv)
{
	data->number_of_philos = (int)ft_aton(argv[1]);
	data->time_to_die = ft_aton(argv[2]);
	data->time_to_eat = ft_aton(argv[3]);
	data->time_to_sleep = ft_aton(argv[4]);
	if (data->number_of_philos == 0 || data->time_to_die == 0 || \
		data->time_to_eat == 0 || data->time_to_sleep == 0)
		return (FAIL);
	data->minimum_meal_count = 0;
	if (argv[5])
	{
		data->minimum_meal_count = ft_aton(argv[5]);
		if (data->minimum_meal_count == 0)
			return (FAIL);
	}
	data->is_end = FALSE;
	if (get_time(&(data->start_time)) == FAIL)
		return (FAIL);
	if (pthread_mutex_init(&data->key, NULL) != 0)
		return (FAIL);
	if (set_fork(data) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

static int	set_philo(t_philo **philo, t_data *data)
{
	int	head_count;
	int	index;

	head_count = data->number_of_philos;
	*philo = (t_philo *)malloc(sizeof(t_philo) * head_count);
	if (philo == NULL)
		return (FAIL);
	index = 0;
	while (index < head_count)
	{
		(*philo)[index].id = index;
		(*philo)[index].left_hand = index;
		(*philo)[index].right_hand = (index - 1 + head_count) % head_count;
		(*philo)[index].data = data;
		(*philo)[index].meal_count = 0;
		(*philo)[index].last_meal = data->start_time;
		if (pthread_mutex_init(&((*philo)[index].key), NULL) != 0)
			return (FAIL);
		index++;
	}
	return (SUCCESS);
}

int	set_var(t_philo **philo, t_data *data, char **argv)
{
	if (set_data(data, argv) == FAIL)
		return (FAIL);
	if (set_philo(philo, data) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
