/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:10:17 by wooseoki          #+#    #+#             */
/*   Updated: 2023/06/10 19:05:21 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_everyone_full(t_philo *philo)
{
	int	min_meal;
	int	index;
	int	total_philo;

	index = 0;
	min_meal = philo->data->minimum_meal_count;
	if (min_meal == 0)
		return (FALSE);
	total_philo = philo->data->number_of_philos;
	while (index < total_philo)
	{
		pthread_mutex_lock(&(philo[index].key));
		if (philo[index].meal_count < min_meal)
		{
			pthread_mutex_unlock(&(philo[index].key));
			return (FALSE);
		}
		pthread_mutex_unlock(&(philo[index].key));
		index++;
	}
	return (TRUE);
}

static void	set_end_state(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->key));
	data->is_end = TRUE;
	pthread_mutex_unlock(&(data->key));
}

static int	is_anyone_starving(t_philo *philo)
{
	int			index;
	int			head_count;
	t_time		now;
	t_time		time_to_die;

	index = 0;
	head_count = philo->data->number_of_philos;
	time_to_die = philo->data->time_to_die;
	while (index < head_count)
	{
		get_time(&now);
		pthread_mutex_lock(&(philo[index].key));
		if ((now - philo[index].last_meal) >= time_to_die)
		{
			pthread_mutex_unlock(&(philo[index].key));
			return (TRUE);
		}
		pthread_mutex_unlock(&(philo[index].key));
		index++;
	}
	return (FALSE);
}

static void	print_died(t_philo *philo)
{
	t_time	now;
	t_time	diff;

	get_time(&now);
	diff = now - philo->data->start_time;
	pthread_mutex_lock(&(philo->data->key));
	printf("%llu %d died\n", diff, philo->id + 1);
	pthread_mutex_unlock(&(philo->data->key));
}

void	start_monitoring(t_philo *philo)
{
	while (TRUE)
	{
		if (is_anyone_starving(philo) == TRUE)
		{
			set_end_state(philo);
			print_died(philo);
			return ;
		}
		if (is_everyone_full(philo) == TRUE)
		{
			set_end_state(philo);
			return ;
		}
		usleep(100);
	}
}
